/*
 * $Id: transformations.h 5997 2009-08-20 12:06:21Z anca_vamanu $
 *
 * Copyright (C) 2007 voice-system.ro
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
 *
 */

/*! \file
 * \brief Transformations support
 */

#ifndef _TRANSFORMATIONS_H_
#define _TRANSFORMATIONS_H_

#include "usr_avp.h"
#include "pvar.h"

#define TR_LBRACKET_STR		"{"
#define TR_LBRACKET		'{'
#define TR_RBRACKET_STR		"}"
#define TR_RBRACKET		'}'
#define TR_CLASS_MARKER		'.'
#define TR_PARAM_MARKER		','

enum _tr_type { TR_NONE=0, TR_STRING, TR_URI, TR_PARAMLIST, TR_NAMEADDR };
enum _tr_s_subtype { 
	TR_S_NONE=0, TR_S_LEN, TR_S_INT, TR_S_MD5, TR_S_SUBSTR,
	TR_S_SELECT, TR_S_ENCODEHEXA, TR_S_DECODEHEXA,
	TR_S_ESCAPECOMMON, TR_S_UNESCAPECOMMON, TR_S_ESCAPEUSER, TR_S_UNESCAPEUSER,
	TR_S_ESCAPEPARAM, TR_S_UNESCAPEPARAM, TR_S_TOLOWER, TR_S_TOUPPER
};
enum _tr_uri_subtype {
	TR_URI_NONE=0, TR_URI_USER, TR_URI_HOST, TR_URI_PASSWD, TR_URI_PORT,
	TR_URI_PARAMS, TR_URI_PARAM, TR_URI_HEADERS, TR_URI_TRANSPORT, TR_URI_TTL,
	TR_URI_UPARAM, TR_URI_MADDR, TR_URI_METHOD, TR_URI_LR,
	TR_URI_R2
};
enum _tr_param_subtype {
	TR_PL_NONE=0, TR_PL_VALUE, TR_PL_VALUEAT, TR_PL_NAME, TR_PL_COUNT
};
enum _tr_nameaddr_subtype {
	TR_NA_NONE=0, TR_NA_NAME, TR_NA_URI, TR_NA_LEN, TR_NA_PARAM
};
enum _tr_param_type { TR_PARAM_NONE=0, TR_PARAM_STRING, TR_PARAM_NUMBER,
	TR_PARAM_SPEC };

typedef struct tr_param_ {
	int type;
	union {
		int n;
		str s;
		void *data;
	} v;
	struct tr_param_ *next;
} tr_param_t, *tr_param_p;

typedef int (*tr_func_t) (struct sip_msg *, tr_param_t*, int, pv_value_t*);

typedef struct trans_ {
	str name;
	int type;
	int subtype;
	tr_func_t trf;
	tr_param_t *params;
	struct trans_ *next;
} trans_t, *trans_p;

int run_transformations(struct sip_msg *msg, trans_t *tr, pv_value_t *val);
char* parse_transformation(str *in, trans_t **tr);
char* tr_parse_string(str* in, trans_t *t);
char* tr_parse_uri(str* in, trans_t *t);
char* tr_parse_paramlist(str* in, trans_t *t);
char* tr_parse_nameaddr(str* in, trans_t *t);
void destroy_transformation(trans_t *t);
void free_transformation(trans_t *t);
void free_tr_param(tr_param_t *tp);

#endif

