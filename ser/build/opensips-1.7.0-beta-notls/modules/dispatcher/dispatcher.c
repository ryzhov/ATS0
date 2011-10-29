/**
 * $Id: dispatcher.c 8037 2011-06-22 12:49:07Z razvancrainea $
 *
 * dispatcher module -- stateless load balancing
 *
 * Copyright (C) 2004-2005 FhG Fokus
 * Copyright (C) 2006-2010 Voice Sistem SRL
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
 * History
 * -------
 * 2004-07-31  first version, by daniel
 * 2007-01-11  Added a function to check if a specific gateway is in a group
 *				(carsten - Carsten Bock, BASIS AudioNet GmbH)
 * 2007-02-09  Added active probing of failed destinations and automatic
 *				re-enabling of destinations (carsten)
 * 2007-05-08  Ported the changes to SVN-Trunk and renamed ds_is_domain
 *				to ds_is_from_list.  (carsten)
 * 2007-07-18  Added support for load/reload groups from DB 
 * 			   reload triggered from ds_reload MI_Command (ancuta)
 * 2009-05-18  Added support for weights for the destinations;
 * 			   added support for custom "attrs" (opaque string) (bogdan)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "../../sr_module.h"
#include "../../mi/mi.h"
#include "../../dprint.h"
#include "../../error.h"
#include "../../ut.h"
#include "../../route.h"
#include "../../mem/mem.h"
#include "../../mod_fix.h"

#include "dispatch.h"



#define DS_SET_ID_COL		"setid"
#define DS_DEST_URI_COL		"destination"
#define DS_DEST_FLAGS_COL	"flags"
#define DS_DEST_WEIGHT_COL	"weight"
#define DS_DEST_ATTRS_COL	"attrs"
#define DS_TABLE_NAME 		"dispatcher"

/** parameters */
char *dslistfile = CFG_DIR"dispatcher.list";
int  ds_force_dst   = 0;
int  ds_flags       = 0; 
int  ds_use_default = 0; 
static str dst_avp_param = {NULL, 0};
static str grp_avp_param = {NULL, 0};
static str cnt_avp_param = {NULL, 0};
static str attrs_avp_param = {NULL, 0};
str hash_pvar_param = {NULL, 0};

int dst_avp_name;
unsigned short dst_avp_type;
int grp_avp_name;
unsigned short grp_avp_type;
int cnt_avp_name;
unsigned short cnt_avp_type;
int attrs_avp_name;
unsigned short attrs_avp_type;

pv_elem_t * hash_param_model = NULL;

int probing_threshhold = 3; /* number of failed requests, before a destination
							   is taken into probing */
str ds_ping_method = {"OPTIONS",7};
str ds_ping_from   = {"sip:dispatcher@localhost", 24};
static int ds_ping_interval = 0;
int ds_probing_mode = 0;

/*db */
str ds_db_url         = {NULL, 0};
str ds_set_id_col     = str_init(DS_SET_ID_COL);
str ds_dest_uri_col   = str_init(DS_DEST_URI_COL);
str ds_dest_flags_col = str_init(DS_DEST_FLAGS_COL);
str ds_dest_weight_col= str_init(DS_DEST_WEIGHT_COL);
str ds_dest_attrs_col = str_init(DS_DEST_ATTRS_COL);
str ds_table_name     = str_init(DS_TABLE_NAME);

str ds_setid_pvname   = {NULL, 0};
pv_spec_t ds_setid_pv;

static str options_reply_codes_str= {0, 0};
static int* options_reply_codes = NULL;
static int options_codes_no; 
static char *probing_sock_s = NULL;
struct socket_info *probing_sock = NULL;

/* event */
static str dispatcher_event = str_init("E_DISPATCHER_STATUS");
event_id_t dispatch_evi_id;

/** module functions */
static int mod_init(void);
static int child_init(int);

static int w_ds_select_dst(struct sip_msg*, char*, char*);
static int w_ds_select_dst_limited(struct sip_msg*, char*, char*, char*);
static int w_ds_select_domain(struct sip_msg*, char*, char*);
static int w_ds_select_domain_limited(struct sip_msg*, char*, char*, char*);
static int w_ds_next_dst(struct sip_msg*, char*, char*);
static int w_ds_next_domain(struct sip_msg*, char*, char*);
static int w_ds_mark_dst0(struct sip_msg*, char*, char*);
static int w_ds_mark_dst1(struct sip_msg*, char*, char*);

static int w_ds_is_in_list2(struct sip_msg*, char*, char*);
static int w_ds_is_in_list3(struct sip_msg*, char*, char*, char*);
static int w_ds_is_in_list4(struct sip_msg*, char*, char*, char*, char*);

static void destroy(void);

static int ds_warn_fixup(void** param, int param_no);
static int in_list_fixup(void** param, int param_no);

static struct mi_root* ds_mi_set(struct mi_root* cmd, void* param);
static struct mi_root* ds_mi_list(struct mi_root* cmd, void* param);
static struct mi_root* ds_mi_reload(struct mi_root* cmd_tree, void* param);
static int mi_child_init(void);


static cmd_export_t cmds[]={
	{"ds_select_dst",    (cmd_function)w_ds_select_dst,    2, fixup_igp_igp, 0,
		REQUEST_ROUTE|FAILURE_ROUTE},
	{"ds_select_dst",    (cmd_function)w_ds_select_dst_limited,    3, fixup_igp_igp_igp, 0,
		REQUEST_ROUTE|FAILURE_ROUTE},
	{"ds_select_domain", (cmd_function)w_ds_select_domain, 2, fixup_igp_igp, 0,
		REQUEST_ROUTE|FAILURE_ROUTE},
	{"ds_select_domain", (cmd_function)w_ds_select_domain_limited, 3, fixup_igp_igp_igp, 0,
		REQUEST_ROUTE|FAILURE_ROUTE},
	{"ds_next_dst",      (cmd_function)w_ds_next_dst,      0, ds_warn_fixup, 0,
		REQUEST_ROUTE|FAILURE_ROUTE},
	{"ds_next_domain",   (cmd_function)w_ds_next_domain,   0, ds_warn_fixup, 0,
		REQUEST_ROUTE|FAILURE_ROUTE},
	{"ds_mark_dst",      (cmd_function)w_ds_mark_dst0,     0, ds_warn_fixup, 0,
		REQUEST_ROUTE|FAILURE_ROUTE},
	{"ds_mark_dst",      (cmd_function)w_ds_mark_dst1,     1, ds_warn_fixup, 0,
		REQUEST_ROUTE|FAILURE_ROUTE},
	{"ds_is_in_list",    (cmd_function)w_ds_is_in_list2,   2, in_list_fixup, 0,
		REQUEST_ROUTE|FAILURE_ROUTE|ONREPLY_ROUTE|BRANCH_ROUTE},
	{"ds_is_in_list",    (cmd_function)w_ds_is_in_list3,   3, in_list_fixup, 0,
		REQUEST_ROUTE|FAILURE_ROUTE|ONREPLY_ROUTE|BRANCH_ROUTE},
	{"ds_is_in_list",    (cmd_function)w_ds_is_in_list4,   4, in_list_fixup, 0,
		REQUEST_ROUTE|FAILURE_ROUTE|ONREPLY_ROUTE|BRANCH_ROUTE},
	{0,0,0,0,0,0}
};


static param_export_t params[]={
	{"list_file",       STR_PARAM, &dslistfile},
	{"db_url",          STR_PARAM, &ds_db_url.s},
	{"table_name",      STR_PARAM, &ds_table_name.s},
	{"setid_col",       STR_PARAM, &ds_set_id_col.s},
	{"destination_col", STR_PARAM, &ds_dest_uri_col.s},
	{"flags_col",       STR_PARAM, &ds_dest_flags_col.s},
	{"weight_col",      STR_PARAM, &ds_dest_weight_col.s},
	{"attrs_col",       STR_PARAM, &ds_dest_attrs_col.s},
	{"force_dst",       INT_PARAM, &ds_force_dst},
	{"flags",           INT_PARAM, &ds_flags},
	{"use_default",     INT_PARAM, &ds_use_default},
	{"dst_avp",         STR_PARAM, &dst_avp_param.s},
	{"grp_avp",         STR_PARAM, &grp_avp_param.s},
	{"cnt_avp",         STR_PARAM, &cnt_avp_param.s},
	{"attrs_avp",       STR_PARAM, &attrs_avp_param.s},
	{"hash_pvar",       STR_PARAM, &hash_pvar_param.s},
	{"setid_pvar",      STR_PARAM, &ds_setid_pvname.s},
	{"ds_probing_threshhold", INT_PARAM, &probing_threshhold},
	{"ds_ping_method",        STR_PARAM, &ds_ping_method.s},
	{"ds_ping_from",          STR_PARAM, &ds_ping_from.s},
	{"ds_ping_interval",      INT_PARAM, &ds_ping_interval},
	{"ds_probing_mode",       INT_PARAM, &ds_probing_mode},
	{"options_reply_codes",   STR_PARAM, &options_reply_codes_str.s},
	{"ds_probing_sock",       STR_PARAM, &probing_sock_s},
	{0,0,0}
};


static mi_export_t mi_cmds[] = {
	{ "ds_set_state",   ds_mi_set,     0,                 0,  0            },
	{ "ds_list",        ds_mi_list,    MI_NO_INPUT_FLAG,  0,  0            },
	{ "ds_reload",      ds_mi_reload,  0,                 0,  mi_child_init},
	{ 0, 0, 0, 0, 0}
};


/** module exports */
struct module_exports exports= {
	"dispatcher",
	MODULE_VERSION,
	DEFAULT_DLFLAGS, /* dlopen flags */
	cmds,
	params,
	0,          /* exported statistics */
	mi_cmds,    /* exported MI functions */
	0,          /* exported pseudo-variables */
	0,          /* extra processes */
	mod_init,   /* module initialization function */
	(response_function) 0,
	(destroy_function) destroy,
	child_init  /* per-child init function */
};


/**
 * init module function
 */
static int mod_init(void)
{
	pv_spec_t avp_spec;

	LM_DBG("initializing ...\n");

	if (dst_avp_param.s)
		dst_avp_param.len = strlen(dst_avp_param.s);
	if (grp_avp_param.s)
		grp_avp_param.len = strlen(grp_avp_param.s);
	if (cnt_avp_param.s)
		cnt_avp_param.len = strlen(cnt_avp_param.s);
	if (attrs_avp_param.s)
		attrs_avp_param.len = strlen(attrs_avp_param.s);
	if (hash_pvar_param.s)
		hash_pvar_param.len = strlen(hash_pvar_param.s);
	if (ds_setid_pvname.s)
		ds_setid_pvname.len = strlen(ds_setid_pvname.s);
	if (ds_ping_from.s) ds_ping_from.len = strlen(ds_ping_from.s);
	if (ds_ping_method.s) ds_ping_method.len = strlen(ds_ping_method.s);

	if(options_reply_codes_str.s)
	{
		options_reply_codes_str.len = strlen(options_reply_codes_str.s);
		if(parse_reply_codes( &options_reply_codes_str, &options_reply_codes,
		&options_codes_no )< 0)
		{
			LM_ERR("Bad format for options_reply_code parameter"
					" - Need a code list separated by commas\n");
			return -1;
		}
	}

	if(init_data()!= 0)
		return -1;

	if(ds_db_url.s)
	{
		ds_db_url.len     = strlen(ds_db_url.s);
		ds_table_name.len = strlen(ds_table_name.s);
		ds_set_id_col.len     = strlen(ds_set_id_col.s);
		ds_dest_uri_col.len   = strlen(ds_dest_uri_col.s);
		ds_dest_flags_col.len = strlen(ds_dest_flags_col.s);
		ds_dest_weight_col.len= strlen(ds_dest_weight_col.s);
		ds_dest_attrs_col.len = strlen(ds_dest_attrs_col.s);

		if(init_ds_db()!= 0)
		{
			LM_ERR("could not initiate a connect to the database\n");
			return -1;
		}
	} else {
		if(ds_load_list(dslistfile)!=0) {
			LM_ERR("no dispatching list loaded from file\n");
			return -1;
		} else {
			LM_DBG("loaded dispatching list\n");
		}
	}

	if (dst_avp_param.s && dst_avp_param.len > 0)
	{
		if (pv_parse_spec(&dst_avp_param, &avp_spec)==0
				|| avp_spec.type!=PVT_AVP)
		{
			LM_ERR("malformed or non AVP %.*s AVP definition\n",
					dst_avp_param.len, dst_avp_param.s);
			return -1;
		}

		if(pv_get_avp_name(0, &(avp_spec.pvp), &dst_avp_name,&dst_avp_type)!=0)
		{
			LM_ERR("[%.*s]- invalid AVP definition\n", dst_avp_param.len,
					dst_avp_param.s);
			return -1;
		}
	} else {
		dst_avp_name = -1;
		dst_avp_type = 0;
	}

	if (grp_avp_param.s && grp_avp_param.len > 0)
	{
		if (pv_parse_spec(&grp_avp_param, &avp_spec)==0
				|| avp_spec.type!=PVT_AVP)
		{
			LM_ERR("malformed or non AVP %.*s AVP definition\n",
					grp_avp_param.len, grp_avp_param.s);
			return -1;
		}

		if(pv_get_avp_name(0, &(avp_spec.pvp), &grp_avp_name,&grp_avp_type)!=0)
		{
			LM_ERR("[%.*s]- invalid AVP definition\n", grp_avp_param.len,
					grp_avp_param.s);
			return -1;
		}
	} else {
		grp_avp_name = -1;
		grp_avp_type = 0;
	}

	if (cnt_avp_param.s && cnt_avp_param.len > 0)
	{
		if (pv_parse_spec(&cnt_avp_param, &avp_spec)==0
				|| avp_spec.type!=PVT_AVP)
		{
			LM_ERR("malformed or non AVP %.*s AVP definition\n",
					cnt_avp_param.len, cnt_avp_param.s);
			return -1;
		}

		if(pv_get_avp_name(0, &(avp_spec.pvp), &cnt_avp_name,&cnt_avp_type)!=0)
		{
			LM_ERR("[%.*s]- invalid AVP definition\n", cnt_avp_param.len,
					cnt_avp_param.s);
			return -1;
		}
	} else {
		cnt_avp_name = -1;
		cnt_avp_type = 0;
	}

	if (attrs_avp_param.s && attrs_avp_param.len > 0) {
		if (pv_parse_spec(&attrs_avp_param, &avp_spec)==0
		|| avp_spec.type!=PVT_AVP) {
			LM_ERR("malformed or non AVP %.*s AVP definition\n",
					attrs_avp_param.len, attrs_avp_param.s);
			return -1;
		}

		if (pv_get_avp_name(0, &(avp_spec.pvp), &attrs_avp_name,
		&attrs_avp_type)!=0){
			LM_ERR("[%.*s]- invalid AVP definition\n", attrs_avp_param.len,
					attrs_avp_param.s);
			return -1;
		}
	} else {
		attrs_avp_name = -1;
		attrs_avp_type = 0;
	}

	if (hash_pvar_param.s && *hash_pvar_param.s) {
		if(pv_parse_format(&hash_pvar_param, &hash_param_model) < 0
				|| hash_param_model==NULL) {
			LM_ERR("malformed PV string: %s\n", hash_pvar_param.s);
			return -1;
		}		
	} else {
		hash_param_model = NULL;
	}

	if(ds_setid_pvname.s!=0)
	{
		if(pv_parse_spec(&ds_setid_pvname, &ds_setid_pv)==NULL
				|| !pv_is_w(&ds_setid_pv))
		{
			LM_ERR("[%s]- invalid setid_pvname\n", ds_setid_pvname.s);
			return -1;
		}
	}
	/* Only, if the Probing-Timer is enabled the TM-API needs to be loaded: */
	if (ds_ping_interval > 0)
	{
		load_tm_f load_tm;
		str host;
		int port,proto;

		if (probing_sock_s && probing_sock_s[0]!=0 ) {
			if (parse_phostport( probing_sock_s, strlen(probing_sock_s),
			&host.s, &host.len, &port, &proto)!=0 ) {
				LM_ERR("socket description <%s> is not valid\n",
					probing_sock_s);
				return -1;
			}
			probing_sock = grep_sock_info( &host, port, proto);
			if (probing_sock==NULL) {
				LM_ERR("socket <%s> is not local to opensips (we must listen "
					"on it\n", probing_sock_s);
				return -1;
			}
		}
		/* TM-Bindings */
		load_tm=(load_tm_f)find_export("load_tm", 0, 0);
		if (load_tm==NULL) {
			LM_ERR("failed to bind to the TM-Module - required for probing\n");
			return -1;
		}
		/* let the auto-loading function load all TM stuff */
		if (load_tm( &tmb ) == -1) {
			LM_ERR("could not load the TM-functions - disable DS ping\n");
			return -1;
		}
		/* Register the PING-Timer */
		if (register_timer(ds_check_timer, NULL, ds_ping_interval)<0) {
			LM_ERR("failed to register timer for probing!\n");
			return -1;
		}
	}

	dispatch_evi_id = evi_publish_event(dispatcher_event); 
	if (dispatch_evi_id == EVI_ERROR)
		LM_ERR("cannot register dispatcher event\n");
	return 0;
}

/**
 * Initialize children
 */
static int child_init(int rank)
{
	
	LM_DBG(" #%d / pid <%d>\n", rank, getpid());

	srand((11+rank)*getpid()*7);

	return 0;
}

static int mi_child_init(void)
{
	
	if(ds_db_url.s)
		return ds_connect_db();
	return 0;

}

/**
 * destroy function
 */
static void destroy(void)
{
	LM_DBG("destroying module ...\n");
	ds_destroy_list();
	if(ds_db_url.s)
		ds_disconnect_db();
}

/**
 *
 */
static int w_ds_select_dst(struct sip_msg* msg, char* set, char* alg)
{
	int a, s;
	
	if(msg==NULL)
		return -1;
	if(fixup_get_ivalue(msg, (gparam_p)set, &s)!=0)
	{
		LM_ERR("no dst set value\n");
		return -1;
	}
	if(fixup_get_ivalue(msg, (gparam_p)alg, &a)!=0)
	{
		LM_ERR("no alg value\n");
		return -1;
	}

	return ds_select_dst(msg, s, a, 0 /*set dst uri*/, 1000);
}

/**
 * same wrapper as w_ds_select_dst, but it allows cutting down the result set
 */
static int w_ds_select_dst_limited(struct sip_msg* msg, char* set, char* alg, char* max_results)
{
	int a, s, m;

	if(msg==NULL)
		return -1;
	if(fixup_get_ivalue(msg, (gparam_p)set, &s)!=0)
	{
		LM_ERR("no dst set value\n");
		return -1;
	}
	if(fixup_get_ivalue(msg, (gparam_p)alg, &a)!=0)
	{
		LM_ERR("no alg value\n");
		return -1;
	}
	if(fixup_get_ivalue(msg, (gparam_p)max_results, &m)!=0)
	{
		LM_ERR("no max results value\n");
		return -1;
	}

	return ds_select_dst(msg, s, a, 0 /*set dst uri*/, m);
}

/**
 *
 */
static int w_ds_select_domain(struct sip_msg* msg, char* set, char* alg)
{
	int a, s;
	if(msg==NULL)
		return -1;

	if(fixup_get_ivalue(msg, (gparam_p)set, &s)!=0)
	{
		LM_ERR("no dst set value\n");
		return -1;
	}
	if(fixup_get_ivalue(msg, (gparam_p)alg, &a)!=0)
	{
		LM_ERR("no alg value\n");
		return -1;
	}

	return ds_select_dst(msg, s, a, 1/*set host port*/, 1000);
}

/**
 *
 */
static int w_ds_select_domain_limited(struct sip_msg* msg, char* set, char* alg, char* max_results)
{
	int a, s, m;
	if(msg==NULL)
		return -1;

	if(fixup_get_ivalue(msg, (gparam_p)set, &s)!=0)
	{
		LM_ERR("no dst set value\n");
		return -1;
	}
	if(fixup_get_ivalue(msg, (gparam_p)alg, &a)!=0)
	{
		LM_ERR("no alg value\n");
		return -1;
	}
	if(fixup_get_ivalue(msg, (gparam_p)max_results, &m)!=0)
	{
		LM_ERR("no max results value\n");
		return -1;
	}

	return ds_select_dst(msg, s, a, 1/*set host port*/, m);
}

/**
 *
 */
static int w_ds_next_dst(struct sip_msg *msg, char *str1, char *str2)
{
	return ds_next_dst(msg, 0/*set dst uri*/);
}

/**
 *
 */
static int w_ds_next_domain(struct sip_msg *msg, char *str1, char *str2)
{
	return ds_next_dst(msg, 1/*set host port*/);
}

/**
 *
 */
static int w_ds_mark_dst0(struct sip_msg *msg, char *str1, char *str2)
{
	return ds_mark_dst(msg, 0);
}

/**
 *
 */
static int w_ds_mark_dst1(struct sip_msg *msg, char *str1, char *str2)
{
	if(str1 && (str1[0]=='i' || str1[0]=='I' || str1[0]=='0'))
		return ds_mark_dst(msg, 0);
	else if(str1 && (str1[0]=='p' || str1[0]=='P' || str1[0]=='2'))
		return ds_mark_dst(msg, 2);
	else
		return ds_mark_dst(msg, 1);
}

static int ds_warn_fixup(void** param, int param_no)
{
	if(!dst_avp_param.s || !grp_avp_param.s || !cnt_avp_param.s)
	{
		LM_ERR("failover functions used, but AVPs paraamters required"
				" are NULL -- feature disabled\n");
	}
	return 0;
}

static int in_list_fixup(void** param, int param_no)
{
	if (param_no==1) {
		/* the ip to test */
		return fixup_pvar(param);
	} else if (param_no==2) {
		/* the port to test */
		if (*param==NULL) {
			return 0;
		} else if ( *((char*)*param)==0 ) {
			pkg_free(*param);
			*param = NULL;
			return 0;
		}
		return fixup_pvar(param);
	} else if (param_no==3) {
		/* the group to check in */
		return fixup_uint(param);
	} else if (param_no==4) {
		/*  active only check ? */
		return fixup_uint(param);
	} else {
		LM_CRIT("bug - too many params (%d) in is_in_list()\n",param_no);
		return -1;
	}
}

/************************** MI STUFF ************************/

static struct mi_root* ds_mi_set(struct mi_root* cmd_tree, void* param)
{
	str sp;
	int ret;
	unsigned int group, state;
	struct mi_node* node;

	node = cmd_tree->node.kids;
	if(node == NULL)
		return init_mi_tree( 400, MI_MISSING_PARM_S, MI_MISSING_PARM_LEN);
	sp = node->value;
	if(sp.len<=0 || !sp.s)
	{
		LM_ERR("bad state value\n");
		return init_mi_tree( 500, "bad state value", 15);
	}

	state = 1;
	if(sp.s[0]=='0' || sp.s[0]=='I' || sp.s[0]=='i')
		state = 0;
	node = node->next;
	if(node == NULL)
		return init_mi_tree( 400, MI_MISSING_PARM_S, MI_MISSING_PARM_LEN);
	sp = node->value;
	if(sp.s == NULL)
	{
		return init_mi_tree(500, "group not found", 15);
	}

	if(str2int(&sp, &group))
	{
		LM_ERR("bad group value\n");
		return init_mi_tree( 500, "bad group value", 16);
	}

	node= node->next;
	if(node == NULL)
		return init_mi_tree( 400, MI_MISSING_PARM_S, MI_MISSING_PARM_LEN);

	sp = node->value;
	if(sp.s == NULL)
	{
		return init_mi_tree(500,"address not found", 18 );
	}

	if(state==1)
		ret = ds_set_state(group, &sp, DS_INACTIVE_DST, 0);
	else
		ret = ds_set_state(group, &sp, DS_INACTIVE_DST, 1);

	if(ret!=0)
	{
		return init_mi_tree(404, "destination not found", 21);
	}

	return init_mi_tree( 200, MI_OK_S, MI_OK_LEN);
}




static struct mi_root* ds_mi_list(struct mi_root* cmd_tree, void* param)
{
	struct mi_root* rpl_tree;

	rpl_tree = init_mi_tree(200, MI_OK_S, MI_OK_LEN);
	if (rpl_tree==NULL)
		return 0;

	if( ds_print_mi_list(&rpl_tree->node)< 0 )
	{
		LM_ERR("failed to add node\n");
		free_mi_tree(rpl_tree);
		return 0;
	}

	return rpl_tree;
}

#define MI_ERR_RELOAD 			"ERROR Reloading data"
#define MI_ERR_RELOAD_LEN 		(sizeof(MI_ERR_RELOAD)-1)
#define MI_NOT_SUPPORTED		"DB mode not configured"
#define MI_NOT_SUPPORTED_LEN 	(sizeof(MI_NOT_SUPPORTED)-1)

static struct mi_root* ds_mi_reload(struct mi_root* cmd_tree, void* param)
{
	if(!ds_db_url.s) {
		if (ds_load_list(dslistfile)!=0)
			return init_mi_tree(500, MI_ERR_RELOAD, MI_ERR_RELOAD_LEN);
	} else {
		if(ds_load_db()<0)
			return init_mi_tree(500, MI_ERR_RELOAD, MI_ERR_RELOAD_LEN);
	}
	return init_mi_tree(200, MI_OK_S, MI_OK_LEN);
}


static int w_ds_is_in_list2(struct sip_msg *msg, char *ip, char *port)
{
	return ds_is_in_list(msg, (pv_spec_t*)ip, (pv_spec_t*)port, -1, 0);
}


static int w_ds_is_in_list3(struct sip_msg *msg,char *ip,char *port,char *set)
{
	return ds_is_in_list(msg,(pv_spec_t*)ip,(pv_spec_t*)port,(int)(long)set,0);
}


static int w_ds_is_in_list4(struct sip_msg *msg,char *ip,char *port,char *set,
															char *active_only)
{
	return ds_is_in_list(msg,(pv_spec_t*)ip,(pv_spec_t*)port,
		(int)(long)set, (int)(long)active_only);
}


int check_options_rplcode(int code)
{
	int i;
	
	for (i =0; i< options_codes_no; i++)
	{
		if(options_reply_codes[i] == code)
			return 1;
	}

	return 0;
}


