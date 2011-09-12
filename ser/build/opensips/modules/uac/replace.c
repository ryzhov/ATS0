/*
 * $Id: replace.c 6130 2009-09-15 17:22:00Z bogdan_iancu $
 *
 * Copyright (C) 2005-2009 Voice Sistem SRL
 *
 * This file is part of opensips, a free SIP server.
 *
 * UAC OpenSIPS-module is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * UAC OpenSIPS-module is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 *
 * History:
 * ---------
 *  2005-01-31  first version (ramona)
 *  2005-08-12  encoded old FROM URI stored in RR hdr and not in FROM anymore;
 *              some TM callbacks replaced with RR callback - more efficient;
 *              XOR used to mix together old and new URI
 *              (bogdan)
 *  2006-03-03  new display name is added even if there is no previous one
 *              (bogdan)
 *  2006-03-03  the RR parameter is encrypted via XOR with a password
 *              (bogdan)
 *  2009-08-22  TO header replacement added (bogdan)
 */


#include <ctype.h>

#include "../../parser/parse_from.h"
#include "../../mem/mem.h"
#include "../../data_lump.h"
#include "../tm/h_table.h"
#include "../tm/tm_load.h"
#include "../rr/api.h"

#include "replace.h"

extern str uac_passwd;
extern int restore_mode;
extern str rr_from_param;
extern str rr_to_param;
extern struct tm_binds uac_tmb;
extern struct rr_binds uac_rrb;

static char enc_table64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz0123456789+/";

static int dec_table64[256];

static void restore_uris_reply(struct cell* c, int t, struct tmcb_params *p);

#define text3B64_len(_l)   ( ( ((_l)+2)/3 ) << 2 )


void init_from_replacer(void)
{
	int i;

	for( i=0 ; i<256 ; i++)
		dec_table64[i] = -1;
	for ( i=0 ; i<64; i++)
		dec_table64[(unsigned char)enc_table64[i]] = i;
	}


static inline int encode_uri( str *src, str *dst )
{
	static char buf[text3B64_len(MAX_URI_SIZE)];
	int  idx;
	int  left;
	int  block;
	int  i,r;
	char *p;

	dst->len = text3B64_len( src->len );
	dst->s = buf;
	if (dst->len>text3B64_len(MAX_URI_SIZE))
	{
		LM_ERR("uri too long\n");
		return -1;
	}

	for ( idx=0, p=buf ; idx<src->len ; idx+=3)
	{
		left = src->len - idx -1 ;
		left = (left>1? 2 : left);

		/* Collect 1 to 3 bytes to encode */
		block = 0;
		for ( i=0,r= 16 ; i<=left ; i++,r-=8 )
		{
			block += ((unsigned char)src->s[idx+i]) << r;
		}

		/* Encode into 2-4 chars appending '=' if not enough data left.*/
		*(p++) = enc_table64[(block >> 18) & 0x3f];
		*(p++) = enc_table64[(block >> 12) & 0x3f];
		*(p++) = left > 0 ? enc_table64[(block >> 6) & 0x3f] : '-';
		*(p++) = left > 1 ? enc_table64[block & 0x3f] : '-';
	}

	return 0;
}


static inline int decode_uri( str *src , str *dst)
{
	static char buf[MAX_URI_SIZE];
	int block;
	int n;
	int idx;
	int end;
	int i,j;
	char c;

	/* Count '-' at end and disregard them */
	for( n=0,i=src->len-1; src->s[i]=='-'; i--)
		n++;

	dst->len = ((src->len * 6) >> 3) - n;
	dst->s = buf;
	if (dst->len>MAX_URI_SIZE)
	{
		LM_ERR("uri too long\n");
		return -1;
	}

	end = src->len - n;
	for ( i=0,idx=0 ; i<end ; idx+=3 )
	{
		/* Assemble three bytes into an int from four "valid" characters */
		block = 0;
		for ( j=0; j<4 && i<end ; j++)
		{
			c = dec_table64[(unsigned char)src->s[i++]];
			if ( c<0 )
			{
				LM_ERR("invalid base64 string\"%.*s\"\n",src->len,src->s);
				return -1;
			}
			block += c << (18 - 6*j);
		}

		/* Add the bytes */
		for ( j=0,n=16 ; j<3 && idx+j< dst->len; j++,n-=8 )
			buf[idx+j] = (char) ((block >> n) & 0xff);
	}

	return 0;
}


static inline struct lump* get_display_anchor(struct sip_msg *msg,
						struct hdr_field *hdr, struct to_body *body, str *dsp)
{
	struct lump* l;
	char *p1;
	char *p2;

	/* is URI quoted or not? */
	p1 = hdr->name.s + hdr->name.len;
	for( p2=body->uri.s-1 ; p2>=p1 && *p2!='<' ; p2--);

	if (*p2=='<') {
		/* is quoted */
		l = anchor_lump( msg, p2 - msg->buf, 0, 0);
		if (l==0) {
			LM_ERR("unable to build lump anchor\n");
			return 0;
		}
		dsp->s[dsp->len++] = ' ';
		return l;
	}

	/* not quoted - more complicated....must place the closing bracket */
	l = anchor_lump( msg, (body->uri.s+body->uri.len) - msg->buf, 0, 0);
	if (l==0) {
		LM_ERR("unable to build lump anchor\n");
		return 0;
	}
	p1 = (char*)pkg_malloc(1);
	if (p1==0) {
		LM_ERR("no more pkg mem \n");
		return 0;
	}
	*p1 = '>';
	if (insert_new_lump_after( l, p1, 1, 0)==0) {
		LM_ERR("insert lump failed\n");
		pkg_free(p1);
		return 0;
	}
	/* build anchor for display */
	l = anchor_lump( msg, body->uri.s - msg->buf, 0, 0);
	if (l==0) {
		LM_ERR("unable to build lump anchor\n");
		return 0;
	}
	dsp->s[dsp->len++] = ' ';
	dsp->s[dsp->len++] = '<';
	return l;
}


/*
 * relace uri and/or display name in FROM / TO header
 */
int replace_uri( struct sip_msg *msg, str *display, str *uri,
										struct hdr_field *hdr, str *rr_param)
{
	static char buf_s[MAX_URI_SIZE];
	struct to_body *body;
	struct lump* l;
	struct cell *Trans;
	str replace;
	char *p;
	str param;
	str buf;
	int uac_flag;
	int i;

	/* consistency check! in AUTO mode, do NOT allow URI changing
	 * in sequential request */
	if (restore_mode==UAC_AUTO_RESTORE && uri && uri->len) {
		if ( msg->to==0 && (parse_headers(msg,HDR_TO_F,0)!=0 || msg->to==0) ) {
			LM_ERR("failed to parse TO hdr\n");
			goto error;
		}
		if (get_to(msg)->tag_value.len!=0) {
			LM_ERR("decline FROM replacing in sequential request "
				"in auto mode (has TO tag)\n");
			goto error;
		}
	}

	body = (struct to_body*)hdr->parsed;

	/* first deal with display name */
	if (display) {
		/* must be replaced/ removed */
		l = 0;
		/* first remove the existing display */
		if ( body->display.len) {
			LM_DBG("removing display [%.*s]\n",
				body->display.len,body->display.s);
			/* build del lump */
			l = del_lump( msg, body->display.s-msg->buf, body->display.len, 0);
			if (l==0) {
				LM_ERR("display del lump failed\n");
				goto error;
			}
		}
		/* some new display to set? */
		if (display->len) {
			/* add the new display exactly over the deleted one */
			buf.s = pkg_malloc( display->len + 2 );
			if (buf.s==0) {
				LM_ERR("no more pkg mem\n");
				goto error;
			}
			memcpy( buf.s, display->s, display->len);
			buf.len =  display->len;
			if (l==0 && (l=get_display_anchor(msg,hdr,body,&buf))==0)
			{
				LM_ERR("failed to insert anchor\n");
				goto error;
			}
			if (insert_new_lump_after( l, buf.s, buf.len, 0)==0)
			{
				LM_ERR("insert new display lump failed\n");
				pkg_free(buf.s);
				goto error;
			}
		}
	}

	/* now handle the URI */
	if (uri==0 || uri->len==0 )
		/* do not touch URI part */
		return 0;

	LM_DBG("uri to replace [%.*s]\n",body->uri.len, body->uri.s);
	LM_DBG("replacement uri is [%.*s]\n",uri->len, uri->s);

	/* build del/add lumps */
	if ((l=del_lump( msg, body->uri.s-msg->buf, body->uri.len, 0))==0) {
		LM_ERR("del lump failed\n");
		goto error;
	}
	p = pkg_malloc( uri->len);
	if (p==0) {
		LM_ERR("no more pkg mem\n");
		goto error;
	}
	memcpy( p, uri->s, uri->len); 
	if (insert_new_lump_after( l, p, uri->len, 0)==0) {
		LM_ERR("insert new lump failed\n");
		pkg_free(p);
		goto error;
	}

	if (restore_mode==UAC_NO_RESTORE)
		return 0;

	/* build RR parameter */
	buf.s = buf_s;
	if ( body->uri.len>uri->len ) {
		if (body->uri.len>MAX_URI_SIZE) {
			LM_ERR("old %.*s uri too long\n",hdr->name.len,hdr->name.s);
			goto error;
		}
		memcpy( buf.s, body->uri.s, body->uri.len);
		for( i=0 ; i<uri->len ; i++ )
			buf.s[i] ^=uri->s[i];
		buf.len = body->uri.len;
	} else {
		if (uri->len>MAX_URI_SIZE) {
			LM_ERR("new %.*s uri too long\n",hdr->name.len,hdr->name.s);
			goto error;
		}
		memcpy( buf.s, uri->s, uri->len);
		for( i=0 ; i<body->uri.len ; i++ )
			buf.s[i] ^=body->uri.s[i];
		buf.len = uri->len;
	}

	/* encrypt parameter ;) */
	if (uac_passwd.len)
		for( i=0 ; i<buf.len ; i++)
			buf.s[i] ^= uac_passwd.s[i%uac_passwd.len];

	/* encode the param */
	if (encode_uri( &buf , &replace)<0 )
	{
		LM_ERR("failed to encode uris\n");
		goto error;
	}
	LM_DBG("encode is=<%.*s> len=%d\n",replace.len,replace.s,replace.len);

	/* add RR parameter */
	param.len = 1+rr_param->len+1+replace.len;
	param.s = (char*)pkg_malloc(param.len);
	if (param.s==0)
	{
		LM_ERR("no more pkg mem\n");
		goto error;
	}
	p = param.s;
	*(p++) = ';';
	memcpy( p, rr_param->s, rr_param->len);
	p += rr_param->len;
	*(p++) = '=';
	memcpy( p, replace.s, replace.len);
	p += replace.len;

	if (uac_rrb.add_rr_param( msg, &param)!=0)
	{
		LM_ERR("add_RR_param failed\n");
		goto error1;
	}

	uac_flag = (hdr==msg->from)?FL_USE_UAC_FROM:FL_USE_UAC_TO;

	if ((msg->msg_flags&uac_flag)==0) {
		/* first time here ? */
		if ((msg->msg_flags&(FL_USE_UAC_FROM|FL_USE_UAC_TO))==0){
			/* add TM callback to restore the FROM/TO hdr in reply */
			if (uac_tmb.register_tmcb( msg, 0, TMCB_RESPONSE_IN,
			restore_uris_reply,0,0)!=1) {
				LM_ERR("failed to install TM callback\n");
				goto error1;
			}
		}
		/* set TO/ FROM sepcific flags */
		msg->msg_flags |= uac_flag;
		if ( (Trans=uac_tmb.t_gett())!=NULL && Trans!=T_UNDEFINED && 
		Trans->uas.request)
			Trans->uas.request->msg_flags |= uac_flag;
	}

	pkg_free(param.s);
	return 0;
error1:
	pkg_free(param.s);
error:
	return -1;
}


/*
 * return  0 - restored
 *        -1 - not restored or error
 */
int restore_uri( struct sip_msg *msg, str *rr_param, int check_from)
{
	struct lump* l;
	str param_val;
	str old_uri;
	str new_uri;
	char *p;
	int i;
	int flag;

	/* we should process only sequntial request, but since we are looking
	 * for Route param, the test is not really required -bogdan */

	LM_DBG("getting '%.*s' Route param\n",
		rr_param->len,rr_param->s);
	/* is there something to restore ? */
	if (uac_rrb.get_route_param( msg, rr_param, &param_val)!=0) {
		LM_DBG("route param '%.*s' not found\n",
			rr_param->len,rr_param->s);
		goto failed;
	}
	LM_DBG("route param is '%.*s' (len=%d)\n",
		param_val.len,param_val.s,param_val.len);

	/* decode the parameter val to a URI */
	if (decode_uri( &param_val, &new_uri)<0 ) {
		LM_ERR("failed to decode uri\n");
		goto failed;
	}

	/* dencrypt parameter ;) */
	if (uac_passwd.len)
		for( i=0 ; i<new_uri.len ; i++)
			new_uri.s[i] ^= uac_passwd.s[i%uac_passwd.len];

	/* check the request direction */
	if ( (check_from && uac_rrb.is_direction( msg, RR_FLOW_UPSTREAM)==0) ||
	(!check_from && uac_rrb.is_direction( msg, RR_FLOW_DOWNSTREAM)==0)  ) {
		/* replace the TO URI */
		if ( msg->to==0 && (parse_headers(msg,HDR_TO_F,0)!=0 || msg->to==0) ) {
			LM_ERR("failed to parse TO hdr\n");
			goto failed;
		}
		old_uri = ((struct to_body*)msg->to->parsed)->uri;
		flag = FL_USE_UAC_TO;
	} else {
		/* replace the FROM URI */
		if ( parse_from_header(msg)<0 ) {
			LM_ERR("failed to find/parse FROM hdr\n");
			goto failed;
		}
		old_uri = ((struct to_body*)msg->from->parsed)->uri;
		flag = FL_USE_UAC_FROM;
	}

	/* get new uri */
	if ( new_uri.len<old_uri.len ) {
		LM_ERR("new URI shorter than old URI\n");
		goto failed;
	}
	for( i=0 ; i<old_uri.len ; i++ )
		new_uri.s[i] ^= old_uri.s[i];
	if (new_uri.len==old_uri.len) {
		for( ; new_uri.len && (new_uri.s[new_uri.len-1]==0) ; new_uri.len-- );
		if (new_uri.len==0) {
			LM_ERR("new URI got 0 len\n");
			goto failed;
		}
	}

	LM_DBG("decoded uris are: new=[%.*s] old=[%.*s]\n",
		new_uri.len, new_uri.s, old_uri.len, old_uri.s);

	/* duplicate the decoded value */
	p = pkg_malloc( new_uri.len);
	if (p==0) {
		LM_ERR("no more pkg mem\n");
		goto failed;
	}
	memcpy( p, new_uri.s, new_uri.len);
	new_uri.s = p;

	/* build del/add lumps */
	l = del_lump( msg, old_uri.s-msg->buf, old_uri.len, 0);
	if (l==0) {
		LM_ERR("del lump failed\n");
		goto failed1;
	}

	if (insert_new_lump_after( l, new_uri.s, new_uri.len, 0)==0) {
		LM_ERR("insert new lump failed\n");
		goto failed1;
	}

	msg->msg_flags |= flag;

	return 0;
failed1:
	pkg_free(new_uri.s);
failed:
	return -1;
}



/************************** RRCB functions ******************************/

void rr_checker(struct sip_msg *msg, str *r_param, void *cb_param)
{
	/* check if the request contains the route param */
	if ( (restore_uri( msg, &rr_from_param, 1/*from*/) +
	restore_uri( msg, &rr_to_param, 0/*to*/) )!= -2 ) {
		/* restore in req performed -> replace in reply */
		/* in callback we need TO/FROM to be parsed- it's already done 
		 * by restore_from_to() function */
		if ( uac_tmb.register_tmcb( msg, 0, TMCB_RESPONSE_IN,
		restore_uris_reply, 0, 0)!=1 ) {
			LM_ERR("failed to install TM callback\n");
				return;
		}
	}
}


/************************** TMCB functions ******************************/


static inline int restore_uri_reply(struct sip_msg *rpl,
						struct hdr_field *rpl_hdr, struct hdr_field *req_hdr)
{
	struct lump* l;
	struct to_body *body;
	str new_val;
	int len;
	char *p;

	/* duplicate the new hdr value */
	body = (struct to_body*)req_hdr->parsed;
	for( p = body->uri.s+body->uri.len, len=0; isspace(p[len]) ; len++ );
	len =  p - body->body.s + ((p[len]=='>') ? (len+1) : 0) ;
	new_val.s = pkg_malloc( len );
	if (new_val.s==0) {
		LM_ERR("no more pkg mem\n");
		return -1;
	}
	memcpy( new_val.s, body->body.s, len);
	new_val.len = len;

	body = (struct to_body*)rpl_hdr->parsed;
	for( p = body->uri.s+body->uri.len, len=0; isspace(p[len]) ; len++ );
	len =  p - body->body.s + ((p[len]=='>') ? (len+1) : 0) ;
	LM_DBG("removing <%.*s>\n", len,body->body.s);
	l = del_lump( rpl, body->body.s-rpl->buf, len, 0);
	if (l==0) {
		LM_ERR("del lump failed\n");
		pkg_free( new_val.s );
		return -1;
	}

	LM_DBG("inserting <%.*s>\n",
			new_val.len,new_val.s);
	if (insert_new_lump_after( l, new_val.s, new_val.len, 0)==0) {
		LM_ERR("insert new lump failed\n");
		pkg_free( new_val.s );
		l->len = 0;
		return -1;
	}

	return 0;
}


/* replace the entire from HDR with the original FROM request */
void restore_uris_reply(struct cell* t, int type, struct tmcb_params *p)
{
	struct sip_msg *req;
	struct sip_msg *rpl;

	if ( !t || !t->uas.request || !p->rpl )
		return;

	req = t->uas.request;
	rpl = p->rpl;

	if (req->msg_flags & FL_USE_UAC_FROM ) {
		/* parse FROM in reply */
		if (parse_from_header( rpl )<0 ) {
			LM_ERR("failed to find/parse FROM hdr\n");
			return;
		}
		if (restore_uri_reply( rpl, rpl->from, req->from)) {
			LM_ERR("failed to restore FROM\n");
		}
	}

	if (req->msg_flags & FL_USE_UAC_TO ) {
		/* parse TO in reply */
		if ( rpl->to==0 && (parse_headers(rpl,HDR_TO_F,0)!=0 || rpl->to==0) ) {
			LM_ERR("failed to parse TO hdr\n");
			return;
		}
		if (restore_uri_reply( rpl, rpl->to, req->to)) {
			LM_ERR("failed to restore FROM\n");
		}
	}
}

