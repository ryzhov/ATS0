/* 
 * $Id: dbase.c 6187 2009-09-25 07:53:35Z bogdan_iancu $ 
 *
 * MySQL module core functions
 *
 * Copyright (C) 2001-2003 FhG Fokus
 * Copyright (C) 2007-2008 1&1 Internet AG
 * Copyright (C) 2009 Voice Sistem SRL
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/**
 * \file
 * \brief Implementation of core functions for the MySQL driver.
 *
 * This file contains the implementation of core functions for the MySQL
 * database driver, for example to submit a query or fetch a result.
 */

#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include <mysql/errmsg.h>
#include <mysql/mysqld_error.h>
#include <mysql/mysql_version.h>
#include "../../mem/mem.h"
#include "../../dprint.h"
#include "../../db/db_query.h"
#include "../../db/db_ut.h"
#include "val.h"
#include "my_con.h"
#include "res.h"
#include "row.h"
#include "db_mysql.h"
#include "dbase.h"



#define run_mysql_cmd( _con, _cmd, _ret, _retry ) \
	do {\
		if ( !CON_DISCON(_con) && (_ret = _cmd) ==0 ) \
			break; \
		/* error -> get and check the code */ \
		_ret = mysql_errno(CON_CONNECTION(_con)); \
		if ( (_ret!=CR_SERVER_GONE_ERROR && _ret!=CR_SERVER_LOST && \
		_ret!=CR_CONNECTION_ERROR && _ret!=CR_CONN_HOST_ERROR && \
		_ret!=ER_UNKNOWN_STMT_HANDLER) || \
		(_ret==0 && memcmp(mysql_error(CON_CONNECTION(_con)), \
		"Lost",4)!=0 && memcmp(mysql_error(CON_CONNECTION(_con)), \
		"Unknown prepared statement",26)!=0 && \
		memcmp(mysql_error(CON_CONNECTION(_con)), \
		"MySQL server has gone",20)!=0) ) { \
			/* generic error */  \
			LM_ERR("driver error: %s\n", mysql_error(CON_CONNECTION(_con))); \
			_ret = -1; \
			break; \
		} \
		/* we got disconnected */ \
		LM_INFO("disconect event for %p\n",(void*)_con->tail); \
		if (CON_DISCON(_con) == 0) { \
			CON_DISCON(_con) = 1; \
			reset_all_statements(_con); \
		} \
		int _i_c; \
		for (_i_c = 0 ; _i_c<3 ; _i_c++) { \
			if ((_ret=db_mysql_connect((struct my_con*)(_con)->tail))==0) { \
				/* we reconnected back */ \
				CON_DISCON(_con) = 0; \
				LM_INFO("re-connected successful for %p\n",(void*)_con->tail);\
				_ret = (_retry)? (_cmd) : 1 ; \
				break;\
			}\
		};\
	}while( 0 )\



static void reset_all_statements(const db_con_t* conn)
{
	struct prep_stmt *pq_ptr;
	struct my_stmt_ctx *ctx;

	LM_INFO("reseting all statements on connection: (%p) %p\n", 
		conn,(void*)conn->tail);
	for( pq_ptr=CON_PS_LIST(conn); pq_ptr ; pq_ptr=pq_ptr->next ) {
		for (ctx = pq_ptr->stmts ; ctx ; ctx=ctx->next ) {
			LM_DBG("resetting statement (%p,%p) for context %p (%.*s)\n",
				pq_ptr,ctx->stmt, ctx, ctx->table.len,ctx->table.s);
			if (ctx->stmt) {
				mysql_stmt_close(ctx->stmt);
				ctx->stmt = NULL;
				ctx->has_out = 0;
			}
		}
	}
}


/**
 * \brief Send a SQL query to the server.
 *
 * Send a SQL query to the database server.
 *
 * \param _h handle for the db
 * \param _s executed query
 * \return zero on success, negative value on failure
 */
static int db_mysql_submit_query(const db_con_t* _h, const str* _s)
{
	int  code;

	if (!_h || !_s || !_s->s) {
		LM_ERR("invalid parameter value\n");
		return -1;
	}

	/* screws up the terminal when the query contains a BLOB :-( (by bogdan)
	 * LM_DBG("submit_query(): %.*s\n", _s->len, _s->s);
	 */

	run_mysql_cmd( _h,
		mysql_real_query(CON_CONNECTION(_h),_s->s,_s->len),
		code, 1);
	if (code==0) return 0;

	return -2;
}


/*
 *	Actually free prep_stmt structure
*/
static void db_mysql_free_pq(struct prep_stmt *pq_ptr)
{
	struct my_stmt_ctx *ctx;
	struct my_stmt_ctx *ctx2;

	if ( pq_ptr == NULL )
		return;

	for(ctx=pq_ptr->stmts ; ctx ; ) {
		ctx2 = ctx;
		ctx = ctx->next;
		if (ctx2->stmt)
			mysql_stmt_close(ctx2->stmt);
		pkg_free(ctx2);
	}

	/* free out part */
	if (pq_ptr->bind_out)
		pkg_free(pq_ptr->bind_out);

	/* free in part and the struct */
	pkg_free(pq_ptr);
}


/*
**	Free all allocated prep_stmt structures
 */
void db_mysql_free_stmt_list(struct prep_stmt *head)
{
	struct prep_stmt *pq_ptr;

	while ( head!= NULL ) {
		pq_ptr = head;
		head = head->next;
		db_mysql_free_pq(pq_ptr);
	}
}


static int has_stmt_ctx(const db_con_t* conn, struct my_stmt_ctx **ctx_p)
{
	struct my_stmt_ctx *ctx;

	if (CON_MYSQL_PS(conn) != NULL) {
		/* search for the context */
		for ( ctx=CON_PS_STMTS(conn) ; ctx ; ctx=ctx->next ) {
			if (ctx->table.len== CON_TABLE(conn)->len &&
			memcmp(ctx->table.s, CON_TABLE(conn)->s, CON_TABLE(conn)->len)==0){
				LM_DBG("ctx found for %.*s\n", ctx->table.len,ctx->table.s);
				*ctx_p = ctx;
				return 1;
			}
		}
	}
	*ctx_p = NULL;
	LM_DBG("ctx not found for %.*s\n",
		CON_TABLE(conn)->len, CON_TABLE(conn)->s);
	return 0;
}

static struct my_stmt_ctx * get_new_stmt_ctx(const db_con_t* conn,
														const str *query)
{
	struct my_stmt_ctx *ctx;
	int code;
	int i;

	/* new one */
	ctx = (struct my_stmt_ctx*)pkg_malloc
		( sizeof(struct my_stmt_ctx) + CON_TABLE(conn)->len + query->len);
	if (ctx==NULL) {
		LM_ERR("no more pkg mem for statement context\n");
		return NULL;
	}
	memset( ctx, 0, 
		sizeof(struct my_stmt_ctx) + CON_TABLE(conn)->len + query->len);
	ctx->table.s = (char*)(ctx+1);
	ctx->table.len = CON_TABLE(conn)->len;
	memcpy( ctx->table.s, CON_TABLE(conn)->s, ctx->table.len);
	ctx->query.s = ctx->table.s + ctx->table.len;
	ctx->query.len = query->len;
	memcpy( ctx->query.s, query->s, query->len);
	ctx->next = 0;
	ctx->has_out = 0;

	for( i=0 ; i<2 ; i++ ) {
		/* initialize the statement */
		if ( ! (ctx->stmt=mysql_stmt_init(CON_CONNECTION(conn))) ) {
			LM_ERR("failed while mysql_stmt_init()\n");
			return NULL;
		}
		run_mysql_cmd( conn,
			mysql_stmt_prepare(ctx->stmt, query->s, query->len),
			code, 0);
		if (code==0) break;
		if (code<0) {
			LM_ERR("failed while mysql_stmt_prepare()\n");
			mysql_stmt_close(ctx->stmt);
			pkg_free(ctx);
			return NULL;
		}
		/* if code==1 (reconnect happend, we try once more */
	}

	return ctx;
}



static struct prep_stmt* alloc_new_prepared_stmt(const db_val_t* v, int n,
			const db_val_t* uv, int un)
{
	struct prep_stmt *pq_ptr;
	MYSQL_TIME *mt;
	int total;
	int time_no;
	int i;
	int len;

	total = n+un;
	time_no = 0;
	for(i=0 ; i<n ;i++)
		if (VAL_TYPE(v+i)==DB_DATETIME) time_no++;
	for(i=0 ; i<un ;i++)
		if (VAL_TYPE(uv+i)==DB_DATETIME) time_no++;

	len = sizeof(struct prep_stmt) + time_no*sizeof(MYSQL_TIME) +
			total*(sizeof(struct bind_icontent) + sizeof(MYSQL_BIND));

	pq_ptr = (struct prep_stmt*)pkg_malloc( len );
	if (pq_ptr==NULL) {
		LM_ERR("no more pkg mem for the a new prepared statement\n");
		return NULL;
	}
	memset( pq_ptr, 0, len);

	/* set the in bind array */
	if (total) {
		pq_ptr->bind_in = (MYSQL_BIND*)(pq_ptr+1);
		pq_ptr->in_bufs = (struct bind_icontent*)(pq_ptr->bind_in + total);
		mt = (MYSQL_TIME*)(pq_ptr->in_bufs + total);

		for( i=0 ; i<n ; i++ ) {
			pq_ptr->bind_in[i].length = &pq_ptr->in_bufs[i].len;
			pq_ptr->bind_in[i].is_null = &pq_ptr->in_bufs[i].null;
			if (VAL_TYPE(v+i)==DB_DATETIME)
				pq_ptr->bind_in[i].buffer = &mt[--time_no];
		}
		for( i=0 ; i<un ; i++ ) {
			pq_ptr->bind_in[n+i].length = &pq_ptr->in_bufs[n+i].len;
			pq_ptr->bind_in[n+i].is_null = &pq_ptr->in_bufs[n+i].null;
			if (VAL_TYPE(uv+i)==DB_DATETIME)
				pq_ptr->bind_in[n+i].buffer = &mt[--time_no];
		}
		if (time_no!=0) {
			LM_CRIT("bug - time_no=%d\n",time_no);
			pkg_free(pq_ptr);
			return NULL;
		}
	}

	return pq_ptr;
}


static int re_init_statement(const db_con_t* conn, struct prep_stmt *pq_ptr,
													struct my_stmt_ctx *ctx)
{
	struct my_stmt_ctx *ctx1, *ctx2;
	int code;
	int i;

	LM_INFO(" query  is <%.*s>, ptr=%p\n",
		ctx->query.len, ctx->query.s, ctx->stmt);
	
	for( i=0 ; i<2 ; i++ ) {
		/* re-init the statement */
		if ( !(ctx->stmt=mysql_stmt_init(CON_CONNECTION(conn))) ) {
			LM_ERR("failed while mysql_stmt_init()\n");
			goto error;
		}
		run_mysql_cmd( conn,
			mysql_stmt_prepare(ctx->stmt, ctx->query.s, ctx->query.len),
			code, 0);
		if (code==0) return 0; /* success */
		if (code<0) {
			LM_ERR("failed while mysql_stmt_prepare()\n");
			break;
		}
		/* if code==1, it means a reconnect happened, so we try once more */
	}

	/* destroy the statement only, but keep the context */
	mysql_stmt_close(ctx->stmt);
	ctx->stmt = NULL;
	return -1;

error:
	/* error -> destroy the context only */
	mysql_stmt_close(ctx->stmt);
	/* remove the context from STMT list */
	for( ctx1=NULL,ctx2=pq_ptr->stmts ; ctx2 ; ) {
		if (ctx2==ctx) {
			if (ctx1)
				ctx1->next = ctx2->next;
			else
				pq_ptr->stmts = ctx2->next;
			break;
		}
		ctx1 = ctx2;
		ctx2 = ctx2->next;
	}
	pkg_free(ctx);
	return -1;
}



/**	Try to exec SQL query using prepared statements API
 **
 **  All query templates and pointers to in/out params are stored in
 **  prep_stmt structure.  This structures organized in two-connected
 **  list and query template searches in this list fistly.
 **
 */
static int db_mysql_do_prepared_query(const db_con_t* conn, const str *query,
	const db_val_t* v, int n, const db_val_t* uv, int un)
{
	int i, code, cols;
	struct prep_stmt *pq_ptr;
	struct my_stmt_ctx *ctx;
	MYSQL_BIND *mysql_bind;

	LM_DBG("conn=%p (tail=%ld) MC=%p\n",conn, conn->tail,CON_CONNECTION(conn));

	if ( CON_MYSQL_PS(conn) == NULL ) {
		/*  First time when this query is run, so we need to init it ->
		**  allocate new structure for prepared statemet and its values
		*/
		LM_DBG("new query=|%.*s|\n", query->len, query->s);
		pq_ptr = alloc_new_prepared_stmt( v, n, uv, un);
		if (pq_ptr==NULL) {
			LM_ERR("failed to allocated a new statement\n");
			return -1;
		}
		/* get a new context */
		ctx = get_new_stmt_ctx(conn, query);
		if (ctx==NULL) {
			LM_ERR("failed to create new context\n");
			pkg_free(pq_ptr);
			return -1;
		}
		/* link it */
		pq_ptr->stmts = ctx;
		/* set it as current */
		pq_ptr->ctx = ctx;
		pq_ptr->cols_out = -1;
		/* set the in bind array */
		mysql_bind = pq_ptr->bind_in;
		/* link it to the connection */
		pq_ptr->next = CON_PS_LIST(conn);
		CON_PS_LIST(conn) = pq_ptr;
		LM_DBG("new statement(%p) on connection: (%p) %p\n", 
			pq_ptr, conn, (void*)conn->tail);
		/* also return it for direct future usage */
		CON_CURR_PS(conn) = pq_ptr;
	} else {
		pq_ptr = CON_MYSQL_PS(conn);
		mysql_bind = pq_ptr->bind_in;
		if (pq_ptr->ctx==NULL) {
			/* get a new context */
			ctx = get_new_stmt_ctx(conn, query);
			if (ctx==NULL) {
				LM_ERR("failed to create new context\n");
				return -1;
			}
			/* link it */
			ctx->next = pq_ptr->stmts;
			pq_ptr->stmts = ctx;
			/* set it as current */
			pq_ptr->ctx = ctx;
		} else {
			ctx = pq_ptr->ctx;
			if ( ctx->stmt==NULL && re_init_statement(conn, pq_ptr, ctx)!=0 ) {
				LM_ERR("failed to re-init statement!\n");
				return -1;
			}
		}
	}

	LM_DBG("set values for the statement run\n");

	/* set first set of values */
	for( i=0 ; i<n ; i++ ) {
		if (db_mysql_val2bind( v+i , mysql_bind, i)<0 ) {
			LM_ERR("val2bind() failed for i=%d (1)\n", i);
			return -1;
		}
	}

	/* set second set of values */
	for( i=0 ; i<un ; i++ ) {
		if (db_mysql_val2bind( uv+i , mysql_bind, i+n)<0 ) {
			LM_ERR("val2bind() failed for i=%d (2)\n", i);
			return -1;
		}
	}

	/* run the query */
	i=0;
	do {
		/* bind in values to the statement */
		LM_DBG("doing BIND_PARAM in...\n");
		if ( mysql_stmt_bind_param(ctx->stmt, mysql_bind) ) {
			LM_ERR("mysql_stmt_bind_param() failed: %s\n",
				mysql_stmt_error(ctx->stmt));
			for(i=0;i<n+un;i++) {
				LM_ERR("param %d was found as type %d\n",
					i,mysql_bind[i].buffer_type);
			}
			return -1;
		}

		CON_RESULT(conn) = mysql_stmt_result_metadata(ctx->stmt);
		if ( ! CON_RESULT(conn) ) {
			cols = 0;
		} else {
			cols = mysql_num_fields(CON_RESULT(conn));
		}

		run_mysql_cmd( conn, mysql_stmt_execute(ctx->stmt) , code , 0);
		if (code<0)
			return -1;
		if (code==1) {
			/* re-init current statement/context */
			LM_INFO("reconnected to mysql server -> re-init the statement\n");
			if ( re_init_statement(conn, pq_ptr, ctx)!=0 ) {
				LM_ERR("failed to re-init statement!\n");
				return -1;
			}
		}
		i++;

	} while (code!=0 && i<2 );

	/* check and get results */
	if ( cols>0 ) {
		LM_DBG("prepared statement has %d columns in result\n",cols);
		/* set the out bind array ? */
		if (pq_ptr->cols_out==-1) {
			pq_ptr->cols_out = cols;
			pq_ptr->bind_out = (MYSQL_BIND*)pkg_malloc
				( cols*(sizeof(struct bind_ocontent) + sizeof(MYSQL_BIND)) );
			if (pq_ptr->bind_out==NULL) {
				db_mysql_free_pq(pq_ptr);
				CON_CURR_PS(conn) = NULL;
				LM_ERR("no more pkg mem for the a new prepared statement\n");
				return -1;
			}
			memset(pq_ptr->bind_out, 0 ,
				cols*(sizeof(struct bind_ocontent) + sizeof(MYSQL_BIND)));

			pq_ptr->out_bufs = (struct bind_ocontent*)(pq_ptr->bind_out+cols);
			mysql_bind = pq_ptr->bind_out;
			/* prepare the pointers */
			for( i=0 ; i<pq_ptr->cols_out ; i++ ) {
				mysql_bind[i].buffer =  pq_ptr->out_bufs[i].buf;
				mysql_bind[i].buffer_type = MYSQL_TYPE_STRING;
				mysql_bind[i].buffer_length = PREP_STMT_VAL_LEN;
				mysql_bind[i].length = &pq_ptr->out_bufs[i].len;
				mysql_bind[i].is_null = &pq_ptr->out_bufs[i].null;
#if (MYSQL_VERSION_ID >= 50030)
				mysql_bind[i].error = &pq_ptr->out_bufs[i].error;
#endif
			}
			/* bind out values to the statement */
			LM_DBG("doing to BIND_PARAM out ...\n");
			if ( mysql_stmt_bind_result(ctx->stmt, mysql_bind) ) {
				LM_ERR("mysql_stmt_bind_result() failed: %s\n",
					mysql_stmt_error(ctx->stmt));
				return -1;
			}
			ctx->has_out = 1;
		} else if (!ctx->has_out) {
			/* bind out values to the statement */
			LM_DBG("doing to BIND_PARAM out ...\n");
			if ( mysql_stmt_bind_result(ctx->stmt, pq_ptr->bind_out) ) {
				LM_ERR("mysql_stmt_bind_result() failed: %s\n",
					mysql_stmt_error(ctx->stmt));
				return -1;
			}
			ctx->has_out = 1;
		}

		if ( mysql_stmt_store_result(ctx->stmt) ) {
			LM_ERR("mysql_stmt_store_result() failed: %s (%d)\n",
				mysql_stmt_error(ctx->stmt),
				mysql_stmt_errno(ctx->stmt));
			return -1;
		}
	}

	return 0;
}


static str query_holder = {NULL,0};
static int db_mysql_submit_dummy_query(const db_con_t* _h, const str* _s)
{
	query_holder = *_s;
	return 0;
}


/**
 * Initialize the database module.
 * No function should be called before this
 * \param _url URL used for initialization
 * \return zero on success, negative value on failure
 */
db_con_t* db_mysql_init(const str* _url)
{
	return db_do_init(_url, (void *)db_mysql_new_connection);
}


/**
 * Shut down the database module.
 * No function should be called after this
 * \param _h handle to the closed connection
 * \return zero on success, negative value on failure
 */
void db_mysql_close(db_con_t* _h)
{
	db_do_close(_h, db_mysql_free_connection);
}


/**
 * Retrieve a result set
 * \param _h handle to the database
 * \param _r result set that should be retrieved
 * \return zero on success, negative value on failure
 */
static int db_mysql_store_result(const db_con_t* _h, db_res_t** _r)
{
	if ((!_h) || (!_r)) {
		LM_ERR("invalid parameter value\n");
		return -1;
	}

	*_r = db_new_result();
	if (*_r == 0) {
		LM_ERR("no memory left\n");
		return -2;
	}

	if (!CON_HAS_PS(_h))
		CON_RESULT(_h) = mysql_store_result(CON_CONNECTION(_h));
	if (!CON_RESULT(_h)) {
		if (mysql_field_count(CON_CONNECTION(_h)) == 0) {
			(*_r)->col.n = 0;
			(*_r)->n = 0;
			goto done;
		} else {
			LM_ERR("driver error: %s\n", mysql_error(CON_CONNECTION(_h)));
			db_free_result(*_r);
			*_r = 0;
			return -3;
		}
	}

	if (db_mysql_convert_result(_h, *_r) < 0) {
		LM_ERR("error while converting result\n");
		pkg_free(*_r);
		*_r = 0;
		/* all mem on opensips API side is already freed by
		 * db_mysql_convert_result in case of error, but we also need
		 * to free the mem from the mysql lib side */
		mysql_free_result(CON_RESULT(_h));
#if (MYSQL_VERSION_ID >= 40100)
		while( mysql_next_result( CON_CONNECTION(_h) ) > 0 ) {
			MYSQL_RES *res = mysql_store_result( CON_CONNECTION(_h) );
			mysql_free_result(res);
		}
#endif
		CON_RESULT(_h) = 0;
		return -4;
	}

done:
#if (MYSQL_VERSION_ID >= 40100)
	while( mysql_next_result( CON_CONNECTION(_h) ) > 0 ) {
		MYSQL_RES *res = mysql_store_result( CON_CONNECTION(_h) );
		mysql_free_result(res);
	}
#endif

	return 0;
}


/**
 * Release a result set from memory.
 * \param _h handle to the database
 * \param _r result set that should be freed
 * \return zero on success, negative value on failure
 */
int db_mysql_free_result(db_con_t* _h, db_res_t* _r)
{
	if ((!_h) || (!_r)) {
		LM_ERR("invalid parameter value\n");
		return -1;
	}

	if (db_free_result(_r) < 0) {
		LM_ERR("unable to free result structure\n");
		return -1;
	}
	mysql_free_result(CON_RESULT(_h));
	CON_RESULT(_h) = 0;
	return 0;
}


/**
 * Query a table for specified rows.
 * \param _h structure representing database connection
 * \param _k key names
 * \param _op operators
 *\param  _v values of the keys that must match
 * \param _c column names to return
 * \param _n number of key=values pairs to compare
 * \param _nc number of columns to return
 * \param _o order by the specified column
 * \param _r pointer to a structure representing the result
 * \return zero on success, negative value on failure
 */
int db_mysql_query(const db_con_t* _h, const db_key_t* _k, const db_op_t* _op,
	     const db_val_t* _v, const db_key_t* _c, const int _n, const int _nc,
	     const db_key_t _o, db_res_t** _r)
{
	int ret;

	if (CON_HAS_PS(_h)) {
		if (CON_HAS_UNINIT_PS(_h)||!has_stmt_ctx(_h,&(CON_MYSQL_PS(_h)->ctx))){
			ret = db_do_query(_h, _k, _op, _v, _c, _n, _nc, _o, NULL,
				db_mysql_val2str, db_mysql_submit_dummy_query, NULL);
			if (ret!=0) return ret;
		}
		ret = db_mysql_do_prepared_query(_h, &query_holder, _v, _n, NULL, 0);
		if (ret!=0) return ret;
		ret = db_mysql_store_result(_h, _r);
		CON_RESET_CURR_PS(_h);
		return ret;
	}
	return db_do_query(_h, _k, _op, _v, _c, _n, _nc, _o, _r,
		db_mysql_val2str, db_mysql_submit_query, db_mysql_store_result);
}

/**
 * Gets a partial result set.
 * \param _h structure representing the database connection
 * \param _r pointer to a structure representing the result
 * \param nrows number of fetched rows
 * \return zero on success, negative value on failure
 */
int db_mysql_fetch_result(const db_con_t* _h, db_res_t** _r, const int nrows)
{
	int rows, i;

	if (!_h || !_r || nrows < 0) {
		LM_ERR("Invalid parameter value\n");
		return -1;
	}

	/* exit if the fetch count is zero */
	if (nrows == 0) {
		db_free_result(*_r);
		*_r = 0;
		return 0;
	}

	if(*_r==0) {
		/* Allocate a new result structure */
		*_r = db_new_result();
		if (*_r == 0) {
			LM_ERR("no memory left\n");
			return -2;
		}

		if (!CON_HAS_PS(_h))
			CON_RESULT(_h) = mysql_store_result(CON_CONNECTION(_h));
		if (!CON_RESULT(_h)) {
			if (mysql_field_count(CON_CONNECTION(_h)) == 0) {
				(*_r)->col.n = 0;
				(*_r)->n = 0;
				return 0;
			} else {
				LM_ERR("driver error: %s\n", mysql_error(CON_CONNECTION(_h)));
				db_free_result(*_r);
				*_r = 0;
				return -3;
			}
		}
		if (db_mysql_get_columns(_h, *_r) < 0) {
			LM_ERR("error while getting column names\n");
			return -4;
		}

		if (CON_HAS_PS(_h)) {
			RES_NUM_ROWS(*_r) = mysql_stmt_num_rows(CON_PS_STMT(_h));
		} else {
			RES_NUM_ROWS(*_r) = mysql_num_rows(CON_RESULT(_h));
		}
		if (!RES_NUM_ROWS(*_r)) {
			LM_DBG("no rows returned from the query\n");
			RES_ROWS(*_r) = 0;
			return 0;
		}

	} else {
		/* free old rows */
		if(RES_ROWS(*_r)!=0)
			db_free_rows(*_r);
		RES_ROWS(*_r) = 0;
		RES_ROW_N(*_r) = 0;
	}

	/* determine the number of rows remaining to be processed */
	rows = RES_NUM_ROWS(*_r) - RES_LAST_ROW(*_r);

	/* If there aren't any more rows left to process, exit */
	if(rows<=0)
		return 0;

	/* if the fetch count is less than the remaining rows to process */
	/* set the number of rows to process (during this call) equal 
	to the fetch count */
	if(nrows < rows)
		rows = nrows;

	RES_ROW_N(*_r) = rows;

	LM_DBG("converting row %d of %d count %d\n", RES_LAST_ROW(*_r),
			RES_NUM_ROWS(*_r), RES_ROW_N(*_r));

	if (db_allocate_rows(*_r, rows)!=0) {
		LM_ERR("no memory left\n");
		return -5;
	}

	for(i = 0; i < rows; i++) {
		if (CON_HAS_PS(_h)) {
			if ( mysql_stmt_fetch(CON_PS_STMT(_h)) == 1 ) {
				LM_ERR("driver error: %s\n", mysql_error(CON_CONNECTION(_h)));
				RES_ROW_N(*_r) = i;
				db_free_rows(*_r);
				return -6;
			}
		} else {
			CON_ROW(_h) = mysql_fetch_row(CON_RESULT(_h));
			if (!CON_ROW(_h)) {
				LM_ERR("driver error: %s\n", mysql_error(CON_CONNECTION(_h)));
				RES_ROW_N(*_r) = i;
				db_free_rows(*_r);
				return -6;
			}
		}
		if (db_mysql_convert_row(_h, *_r, &(RES_ROWS(*_r)[i])) < 0) {
			LM_ERR("error while converting row #%d\n", i);
			RES_ROW_N(*_r) = i;
			db_free_rows(*_r);
			return -7;
		}
	}

	/* update the total number of rows processed */
	RES_LAST_ROW(*_r) += rows;
	return 0;
}

/**
 * Execute a raw SQL query.
 * \param _h handle for the database
 * \param _s raw query string
 * \param _r result set for storage
 * \return zero on success, negative value on failure
 */
int db_mysql_raw_query(const db_con_t* _h, const str* _s, db_res_t** _r)
{
	CON_RESET_CURR_PS(_h); /* no prepared statements support */
	return db_do_raw_query(_h, _s, _r, db_mysql_submit_query,
	db_mysql_store_result);
}


/**
 * Insert a row into a specified table.
 * \param _h structure representing database connection
 * \param _k key names
 * \param _v values of the keys
 * \param _n number of key=value pairs
 * \return zero on success, negative value on failure
 */
int db_mysql_insert(const db_con_t* _h, const db_key_t* _k, const db_val_t* _v, const int _n)
{
	int ret;

	if (CON_HAS_PS(_h)) {
		if (CON_HAS_UNINIT_PS(_h)||!has_stmt_ctx(_h,&(CON_MYSQL_PS(_h)->ctx))){
			ret = db_do_insert(_h, _k, _v, _n, db_mysql_val2str,
				db_mysql_submit_dummy_query);
			if (ret!=0) return ret;
		}
		ret = db_mysql_do_prepared_query(_h, &query_holder, _v, _n, NULL, 0);
		CON_RESET_CURR_PS(_h);
		return ret;
	}
	return db_do_insert(_h, _k, _v, _n, db_mysql_val2str,
		db_mysql_submit_query);
}


/**
 * Delete a row from the specified table
 * \param _h structure representing database connection
 * \param _k key names
 * \param _o operators
 * \param _v values of the keys that must match
 * \param _n number of key=value pairs
 * \return zero on success, negative value on failure
 */
int db_mysql_delete(const db_con_t* _h, const db_key_t* _k, const db_op_t* _o,
	const db_val_t* _v, const int _n)
{
	int ret;

	if (CON_HAS_PS(_h)) {
		if (CON_HAS_UNINIT_PS(_h)||!has_stmt_ctx(_h,&(CON_MYSQL_PS(_h)->ctx))){
			ret = db_do_delete(_h, _k, _o, _v, _n, db_mysql_val2str,
				db_mysql_submit_dummy_query);
			if (ret!=0) return ret;
		}
		ret = db_mysql_do_prepared_query(_h, &query_holder, _v, _n, NULL, 0);
		CON_RESET_CURR_PS(_h);
		return ret;
	}
	return db_do_delete(_h, _k, _o, _v, _n, db_mysql_val2str,
		db_mysql_submit_query);
}


/**
 * Update some rows in the specified table
 * \param _h structure representing database connection
 * \param _k key names
 * \param _o operators
 * \param _v values of the keys that must match
 * \param _uk updated columns
 * \param _uv updated values of the columns
 * \param _n number of key=value pairs
 * \param _un number of columns to update
 * \return zero on success, negative value on failure
 */
int db_mysql_update(const db_con_t* _h, const db_key_t* _k, const db_op_t* _o, 
	const db_val_t* _v, const db_key_t* _uk, const db_val_t* _uv, const int _n, 
	const int _un)
{
	int ret;

	if (CON_HAS_PS(_h)) {
		if (CON_HAS_UNINIT_PS(_h)||!has_stmt_ctx(_h,&(CON_MYSQL_PS(_h)->ctx))){
			ret = db_do_update(_h, _k, _o, _v, _uk, _uv, _n, _un,
				db_mysql_val2str, db_mysql_submit_dummy_query);
			if (ret!=0) return ret;
		}
		ret = db_mysql_do_prepared_query(_h, &query_holder, _uv, _un, _v, _n);
		CON_RESET_CURR_PS(_h);
		return ret;
	}
	return db_do_update(_h, _k, _o, _v, _uk, _uv, _n, _un, db_mysql_val2str,
		db_mysql_submit_query);
}


/**
 * Just like insert, but replace the row if it exists.
 * \param _h database handle
 * \param _k key names
 * \param _v values of the keys that must match
 * \param _n number of key=value pairs
 * \return zero on success, negative value on failure
 */
int db_mysql_replace(const db_con_t* _h, const db_key_t* _k, const db_val_t* _v, const int _n)
{
	int ret;

	if (CON_HAS_PS(_h)) {
		if (CON_HAS_UNINIT_PS(_h)||!has_stmt_ctx(_h,&(CON_MYSQL_PS(_h)->ctx))){
			ret = db_do_replace(_h, _k, _v, _n, db_mysql_val2str,
				db_mysql_submit_dummy_query);
			if (ret!=0) return ret;
		}
		ret = db_mysql_do_prepared_query(_h, &query_holder, _v, _n, NULL, 0);
		CON_RESET_CURR_PS(_h);
		return ret;
	}
	return db_do_replace(_h, _k, _v, _n, db_mysql_val2str,
		db_mysql_submit_query);
}


/**
 * Returns the last inserted ID.
 * \param _h database handle
 * \return returns the ID as integer or returns 0 if the previous statement
 * does not use an AUTO_INCREMENT value.
 */
int db_last_inserted_id(const db_con_t* _h)
{
	if (!_h) {
		LM_ERR("invalid parameter value\n");
		return -1;
	}
	return mysql_insert_id(CON_CONNECTION(_h));
}


 /**
  * Insert a row into a specified table, update on duplicate key.
  * \param _h structure representing database connection
  * \param _k key names
  * \param _v values of the keys
  * \param _n number of key=value pairs
 */
 int db_insert_update(const db_con_t* _h, const db_key_t* _k, const db_val_t* _v,
	const int _n)
 {
	int off, ret;
	static str  sql_str;
	static char sql_buf[SQL_BUF_LEN];
 
	if ((!_h) || (!_k) || (!_v) || (!_n)) {
		LM_ERR("invalid parameter value\n");
		return -1;
	}
 
	CON_RESET_CURR_PS(_h); /* no prepared statements support */

	ret = snprintf(sql_buf, SQL_BUF_LEN, "insert into %.*s (",
		CON_TABLE(_h)->len, CON_TABLE(_h)->s);
	if (ret < 0 || ret >= SQL_BUF_LEN) goto error;
	off = ret;

	ret = db_print_columns(sql_buf + off, SQL_BUF_LEN - off, _k, _n);
	if (ret < 0) return -1;
	off += ret;

	ret = snprintf(sql_buf + off, SQL_BUF_LEN - off, ") values (");
	if (ret < 0 || ret >= (SQL_BUF_LEN - off)) goto error;
	off += ret;
	ret = db_print_values(_h, sql_buf + off, SQL_BUF_LEN - off, _v, _n,
		db_mysql_val2str);
	if (ret < 0) return -1;
	off += ret;

	*(sql_buf + off++) = ')';
	
	ret = snprintf(sql_buf + off, SQL_BUF_LEN - off, " on duplicate key update ");
	if (ret < 0 || ret >= (SQL_BUF_LEN - off)) goto error;
	off += ret;
	
	ret = db_print_set(_h, sql_buf + off, SQL_BUF_LEN - off, _k, _v, _n,
		db_mysql_val2str);
	if (ret < 0) return -1;
	off += ret;
	
	sql_str.s = sql_buf;
	sql_str.len = off;
 
	if (db_mysql_submit_query(_h, &sql_str) < 0) {
		LM_ERR("error while submitting query\n");
		return -2;
	}
	return 0;

error:
	LM_ERR("error while preparing insert_update operation\n");
	return -1;
}


/**
 * Store the name of table that will be used by subsequent database functions
 * \param _h database handle
 * \param _t table name
 * \return zero on success, negative value on failure
 */
int db_mysql_use_table(db_con_t* _h, const str* _t)
{
	return db_use_table(_h, _t);
}
