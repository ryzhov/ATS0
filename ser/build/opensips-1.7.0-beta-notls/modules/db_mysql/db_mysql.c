/* 
 * $Id: db_mysql.c 8031 2011-06-21 16:33:03Z vladut-paiu $ 
 *
 * MySQL module interface
 *
 * Copyright (C) 2001-2003 FhG Fokus
 * Copyright (C) 2008 1&1 Internet AG
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
/*
 * History:
 * --------
 *  2003-03-11  updated to the new module exports interface (andrei)
 *  2003-03-16  flags export parameter added (janakj)
 */

#include "../../sr_module.h"
#include "../../db/db.h"
#include "../../db/db_cap.h"
#include "dbase.h"
#include "db_mysql.h"

#include <mysql/mysql.h>

unsigned int db_mysql_ping_interval = 5 * 60; /* Default is 5 minutes */
unsigned int db_mysql_timeout_interval = 2;   /* Default is 6 seconds */
unsigned int db_mysql_exec_query_threshold = 0;   /* Warning in case DB query
											takes too long disabled by default*/

static int mysql_mod_init(void);



int db_mysql_bind_api(const str* mod, db_func_t *dbb);

/*
 * MySQL database module interface
 */
static cmd_export_t cmds[] = {
	{"db_bind_api",         (cmd_function)db_mysql_bind_api,      0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0}
};


/*
 * Exported parameters
 */
static param_export_t params[] = {
	{"ping_interval",    INT_PARAM, &db_mysql_ping_interval},
	{"timeout_interval", INT_PARAM, &db_mysql_timeout_interval},
	{"exec_query_threshold", INT_PARAM, &db_mysql_exec_query_threshold},
	{0, 0, 0}
};


struct module_exports exports = {	
	"db_mysql",
	MODULE_VERSION,
	DEFAULT_DLFLAGS, /* dlopen flags */
	cmds,
	params,          /*  module parameters */
	0,               /* exported statistics */
	0,               /* exported MI functions */
	0,               /* exported pseudo-variables */
	0,               /* extra processes */
	mysql_mod_init,  /* module initialization function */
	0,               /* response function*/
	0,               /* destroy function */
	0                /* per-child init function */
};


static int mysql_mod_init(void)
{
	LM_DBG("mysql: MySQL client version is %s\n", mysql_get_client_info());
	return 0;
}

int db_mysql_bind_api(const str* mod, db_func_t *dbb)
{
	if(dbb==NULL)
		return -1;

	memset(dbb, 0, sizeof(db_func_t));

	dbb->use_table        = db_mysql_use_table;
	dbb->init             = db_mysql_init;
	dbb->close            = db_mysql_close;
	dbb->query            = db_mysql_query;
	dbb->fetch_result     = db_mysql_fetch_result;
	dbb->raw_query        = db_mysql_raw_query;
	dbb->free_result      = db_mysql_free_result;
	dbb->insert           = db_mysql_insert;
	dbb->delete           = db_mysql_delete; 
	dbb->update           = db_mysql_update;
	dbb->replace          = db_mysql_replace;
	dbb->last_inserted_id = db_last_inserted_id;
	dbb->insert_update    = db_insert_update;

	dbb->cap |= DB_CAP_MULTIPLE_INSERT;
	return 0;
}

