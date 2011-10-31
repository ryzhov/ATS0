/*
 * $Id: load_balancer.c 8125 2011-07-02 11:43:39Z razvancrainea $
 *
 * load balancer module - complex call load balancing
 *
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
 *
 * History:
 * --------
 *  2009-02-01 initial version (bogdan)
 */

#include "../../sr_module.h"
#include "../../db/db.h"
#include "../../dprint.h"
#include "../../error.h"
#include "../../timer.h"
#include "../../ut.h"
#include "../../mod_fix.h"
#include "../../rw_locking.h"
#include "../../usr_avp.h"
#include "../dialog/dlg_load.h"
#include "../tm/tm_load.h"
#include "lb_parser.h"
#include "lb_db.h"
#include "lb_data.h"
#include "lb_prober.h"




/* db stuff */
static str db_url = {NULL, 0};
static char *table_name = NULL;

/* dialog stuff */
struct dlg_binds lb_dlg_binds;

/* reader-writers lock for data reloading */
static rw_lock_t *ref_lock = NULL; 
static struct lb_data **curr_data = NULL;

/* probing related stuff */
static unsigned int lb_prob_interval = 30;
static str lb_probe_replies = {NULL,0};
struct tm_binds lb_tmb;
str lb_probe_method = str_init("OPTIONS");
str lb_probe_from = str_init("sip:prober@localhost");
static int* probing_reply_codes = NULL;
static int probing_codes_no = 0;

static int mod_init(void);
static int child_init(int rank);
static void mod_destroy(void);
static int mi_child_init();

/* failover stuff */
static str grp_avp_name_s = str_init("lb_grp");
static str mask_avp_name_s = str_init("lb_mask");
static str id_avp_name_s = str_init("lb_id");
int grp_avp_name;
int mask_avp_name;
int id_avp_name;



static struct mi_root* mi_lb_reload(struct mi_root *cmd_tree, void *param);
static struct mi_root* mi_lb_resize(struct mi_root *cmd_tree, void *param);
static struct mi_root* mi_lb_list(struct mi_root *cmd_tree, void *param);
static struct mi_root* mi_lb_status(struct mi_root *cmd_tree, void *param);

static int fixup_resources(void** param, int param_no);

static int w_load_balance(struct sip_msg *req, char *grp,  char *rl, char* al);
static int w_lb_disable(struct sip_msg *req);

static void lb_prob_handler(unsigned int ticks, void* param);




static cmd_export_t cmds[]={
	{"load_balance", (cmd_function)w_load_balance,      2, fixup_resources,
			0, REQUEST_ROUTE|BRANCH_ROUTE|FAILURE_ROUTE},
	{"load_balance", (cmd_function)w_load_balance,      3, fixup_resources,
			0, REQUEST_ROUTE|BRANCH_ROUTE|FAILURE_ROUTE},
	{"lb_disable", (cmd_function)w_lb_disable,          0,               0,
			0, REQUEST_ROUTE|FAILURE_ROUTE},
	{0,0,0,0,0,0}
	};


static param_export_t mod_params[]={
	{ "db_url",                STR_PARAM, &db_url.s                 },
	{ "db_table",              STR_PARAM, &table_name               },
	{ "probing_interval",      INT_PARAM, &lb_prob_interval         },
	{ "probing_method",        STR_PARAM, &lb_probe_method.s        },
	{ "probing_from",          STR_PARAM, &lb_probe_from.s          },
	{ "probing_reply_codes",   STR_PARAM, &lb_probe_replies.s       },
	{ 0,0,0 }
};


static mi_export_t mi_cmds[] = {
	{ "lb_reload",   mi_lb_reload,   MI_NO_INPUT_FLAG,   0,  mi_child_init},
	{ "lb_resize",   mi_lb_resize,   0,                  0,  0},
	{ "lb_list",     mi_lb_list,     MI_NO_INPUT_FLAG,   0,  0},
	{ "lb_status",   mi_lb_status,   0,                  0,  0},
	{ 0, 0, 0, 0, 0}
};



struct module_exports exports= {
	"load_balancer",  /* module's name */
	MODULE_VERSION,
	DEFAULT_DLFLAGS, /* dlopen flags */
	cmds,            /* exported functions */
	mod_params,      /* param exports */
	0,               /* exported statistics */
	mi_cmds,         /* exported MI functions */
	0,               /* exported pseudo-variables */
	0,               /* extra processes */
	mod_init,        /* module initialization function */
	0,               /* reply processing function */
	mod_destroy,
	child_init       /* per-child init function */
};


struct lb_grp_param {
	int grp_no;
	pv_spec_t *grp_pv;
};


static int fixup_resources(void** param, int param_no)
{
	struct lb_res_str_list *lb_rl;
	struct lb_grp_param *lbgp;
	struct lb_res_parse *lbp;
	pv_elem_t *model=NULL;
	str s;

	if (param_no==1) {

		lbgp = (struct lb_grp_param *)pkg_malloc(sizeof(struct lb_grp_param));
		if (lbgp==NULL) {
			LM_ERR("no more pkg mem\n");
			return E_OUT_OF_MEM;
		}
		/* try first as number */
		s.s = (char*)*param;
		s.len = strlen(s.s);
		if (str2int(&s, (unsigned int*)&lbgp->grp_no)==0) {
			lbgp->grp_pv = NULL;
			pkg_free(*param);
		} else {
			lbgp->grp_pv = (pv_spec_t*)pkg_malloc(sizeof(pv_spec_t));
			if (lbgp->grp_pv==NULL) {
				LM_ERR("no pkg memory left\n");
				return E_OUT_OF_MEM;
			}
			if (pv_parse_spec(&s, lbgp->grp_pv)==0 ||
			lbgp->grp_pv->type==PVT_NULL) {
				LM_ERR("%s is not interger nor PV !\n", (char*)*param);
				return E_UNSPEC;
			}
		}
		*param=(void *)(unsigned long)lbgp;
		return 0;

	} else if (param_no==2) {

		/* parameter is string (semi-colon separated list) 
		 * of needed resources */
		lbp = (struct lb_res_parse *)pkg_malloc(sizeof(struct lb_res_parse));
		if (!lbp) {
			LM_ERR("no more pkg mem\n");
			return E_OUT_OF_MEM;
		}
		s.s = (char*)*param;
		s.len = strlen(s.s);

		if(pv_parse_format(&s ,&model) || model==NULL) {
			LM_ERR("wrong format [%s] in resource list!\n", s.s);
			return E_CFG;
		}
		/* check if there is any pv in string */
		if (!model->spec.getf && !model->next)
			lbp->type = RES_TEXT;
		else
			lbp->type = RES_ELEM;

		if (lbp->type & RES_TEXT) {
			lb_rl = parse_resources_list( (char *)(*param), 0);
			if (lb_rl==NULL) {
				LM_ERR("invalid paramter %s\n",(char *)(*param));
				return E_CFG;
			}
			pkg_free(*param);
			lbp->param = (void*)(unsigned long)lb_rl;
		} else {
			lbp->param = (void*)(unsigned long)model;
		}
		*param = (void *)(unsigned long)lbp;

	} else if (param_no==3) {

		fixup_uint(param);

	}

	return 0;
}


static inline int lb_reload_data( void )
{
	struct lb_data *new_data;
	struct lb_data *old_data;

	new_data = load_lb_data();
	if ( new_data==0 ) {
		LM_CRIT("failed to load load-balancing info\n");
		return -1;
	}

	lock_start_write( ref_lock );

	/* no more activ readers -> do the swapping */
	old_data = *curr_data;
	*curr_data = new_data;

	lock_stop_write( ref_lock );

	/* destroy old data */
	if (old_data)
		free_lb_data( old_data );

	return 0;
}




static int mod_init(void)
{
	LM_INFO("Load-Balancer module - initializing\n");

	init_db_url( db_url , 0 /*cannot be null*/);

	/* Load dialog API */
	if (load_dlg_api(&lb_dlg_binds) != 0) {
		LM_ERR("Can't load dialog hooks");
		return -1;
	}

	/* data pointer in shm */
	curr_data = (struct lb_data**)shm_malloc( sizeof(struct lb_data*) );
	if (curr_data==0) {
		LM_CRIT("failed to get shm mem for data ptr\n");
		return -1;
	}
	*curr_data = 0;

	/* create & init lock */
	if ((ref_lock = lock_init_rw()) == NULL) {
		LM_CRIT("failed to init lock\n");
		return -1;
	}

	/* init and open DB connection */
	if (init_lb_db(&db_url, table_name)!=0) {
		LM_ERR("failed to initialize the DB support\n");
		return -1;
	}

	/* load data */
	if ( lb_reload_data()!=0 ) {
		LM_CRIT("failed to load load-balancing data\n");
		return -1;
	}

	/* close DB connection */
	lb_close_db();

	/* arm a function for probing */
	if (lb_prob_interval) {
		/* load TM API */
		if (load_tm_api(&lb_tmb)!=0) {
			LM_ERR("can't load TM API\n");
			return -1;
		}

		/* probing method */
		lb_probe_method.len = strlen(lb_probe_method.s);
		lb_probe_from.len = strlen(lb_probe_from.s);
		if (lb_probe_replies.s)
			lb_probe_replies.len = strlen(lb_probe_replies.s);

		/* register pinger function */
		if (register_timer( lb_prob_handler , NULL, lb_prob_interval)<0) {
			LM_ERR("failed to register probing handler\n");
			return -1;
		}

		if (lb_probe_replies.s) {
			lb_probe_replies.len = strlen(lb_probe_replies.s);
			if(parse_reply_codes( &lb_probe_replies, &probing_reply_codes,
			&probing_codes_no )< 0) {
				LM_ERR("Bad format for options_reply_code parameter"
					" - Need a code list separated by commas\n");
				return -1;
			}
		}

	}

	/* parse avps */
	if (parse_avp_spec(&grp_avp_name_s, &grp_avp_name)) {
		LM_ERR("cannot parse group avp\n");
		return -1;
	}
	if (parse_avp_spec(&mask_avp_name_s, &mask_avp_name)) {
		LM_ERR("cannot parse mask avp\n");
		return -1;
	}
	if (parse_avp_spec(&id_avp_name_s, &id_avp_name)) {
		LM_ERR("cannot parse id avp\n");
		return -1;
	}

	return 0;
}


static int child_init(int rank)
{
	return 0;
}


static int mi_child_init( void )
{
	/* init DB connection */
	if ( lb_connect_db(&db_url)!=0 ) {
		LM_CRIT("cannot initialize database connection\n");
		return -1;
	}
	return 0;
}



static void mod_destroy(void)
{
	/* destroy data */
	if ( curr_data) {
		if (*curr_data)
			free_lb_data( *curr_data );
		shm_free( curr_data );
		curr_data = 0;
	}

	/* destroy lock */
	if (ref_lock) {
		lock_destroy_rw( ref_lock );
		ref_lock = 0;
	}
}


static int w_load_balance(struct sip_msg *req, char *grp, char *rl, char *al)
{
	int ret;
	int grp_no;
	struct lb_grp_param *lbgp = (struct lb_grp_param *)grp;
	pv_value_t val;
	struct lb_res_str_list *lb_rl;
	struct lb_res_parse *lbp;
	pv_elem_t *model;
	str dest;

	lock_start_read( ref_lock );

	if (lbgp->grp_pv) {
		if (pv_get_spec_value( req, (pv_spec_p)lbgp->grp_pv, &val)!=0) {
			LM_ERR("failed to get PV value\n");
			return -1;
		}
		if ( (val.flags&PV_VAL_INT)==0 ) {
			LM_ERR("PV vals is not integer\n");
			return -1;
		}
		grp_no = val.ri;
	} else {
		grp_no = lbgp->grp_no;
	}

	lbp = (struct lb_res_parse *)rl;
	if (lbp->type & RES_ELEM) {
		model = (pv_elem_p)lbp->param;
		if (pv_printf_s(req, model, &dest) || dest.len <= 0) {
			LM_ERR("cannot create resource string\n");
			return -1;
		}
		lb_rl = parse_resources_list(dest.s, 0);
		if (!lb_rl) {
			LM_ERR("cannot create resource list\n");
			return -1;
		}
	} else
		lb_rl = (struct lb_res_str_list *)lbp->param;

	/* do lb */
	ret = do_load_balance(req, grp_no, lb_rl,
			(unsigned int)(long)al, *curr_data);

	lock_stop_read( ref_lock );
	if (lbp->type & RES_ELEM)
		pkg_free(lb_rl);

	if (ret<0)
		return ret;
	return 1;
}


static int w_lb_disable(struct sip_msg *req)
{
	int ret;

	lock_start_read( ref_lock );

	/* do lb */
	ret = do_lb_disable( req , *curr_data);

	lock_stop_read( ref_lock );

	if (ret<0)
		return ret;
	return 1;
}

/******************** PROBING Stuff ***********************/


static int check_options_rplcode(int code)
{
	int i;

	for (i =0; i< probing_codes_no; i++) {
		if(probing_reply_codes[i] == code)
			return 1;
	}

	return 0;
}



void set_dst_state_from_rplcode( int id, int code)
{
	struct lb_dst *dst;

	lock_start_read( ref_lock );

	for( dst=(*curr_data)->dsts ; dst && dst->id!=id ; dst=dst->next);
	if (dst==NULL) {
		lock_stop_read( ref_lock );
		return;
	}

	if ((code == 200) || check_options_rplcode(code)) {
		/* re-enable to DST  (if allowed) */
		if ( dst->flags&LB_DST_STAT_NOEN_FLAG ) {
			lock_stop_read( ref_lock );
			return;
		}
		dst->flags &= ~LB_DST_STAT_DSBL_FLAG;
		lock_stop_read( ref_lock );
		return;
	}

	if (code>=400) {
		dst->flags |= LB_DST_STAT_DSBL_FLAG;
	}

	lock_stop_read( ref_lock );
}



static void lb_prob_handler(unsigned int ticks, void* param)
{
	lock_start_read( ref_lock );

	/* do probing */
	lb_do_probing(*curr_data);

	lock_stop_read( ref_lock );
}


/******************** MI commands ***********************/

static struct mi_root* mi_lb_reload(struct mi_root *cmd_tree, void *param)
{
	LM_INFO("\"lb_reload\" MI command received!\n");

	if ( lb_reload_data()!=0 ) {
		LM_CRIT("failed to load load balancing data\n");
		goto error;
	}

	return init_mi_tree( 200, MI_OK_S, MI_OK_LEN);
error:
	return init_mi_tree( 500, "Failed to reload",16);
}

/*! \brief
 * Expects 3 nodes: 
 *        destination ID (number)
 *        resource name (string)
 *        size (number)
 */

static struct mi_root* mi_lb_resize(struct mi_root *cmd, void *param)
{
	struct mi_root *rpl_tree;
	struct lb_dst *dst;
	struct mi_node *node;
	unsigned int  id, size;
	str *name;
	int n;

	for( n=0,node = cmd->node.kids; n<3 && node ; n++,node=node->next );
	if (n!=3 || node!=0)
		return init_mi_tree( 400, MI_MISSING_PARM_S, MI_MISSING_PARM_LEN);

	node = cmd->node.kids;

	/* id (param 1) */
	if (str2int( &node->value, &id) < 0)
		goto bad_syntax;

	/* resource (param 2) */
	node = node->next;
	name = &node->value;

	/* id (param 3) */
	node = node->next;
	if (str2int( &node->value, &size) < 0)
		goto bad_syntax;

	lock_start_read( ref_lock );

	/* get destination */
	for( dst=(*curr_data)->dsts ; dst && dst->id!=id ; dst=dst->next);
	if (dst==NULL) {
		rpl_tree = init_mi_tree( 404, MI_SSTR("Destination ID not found"));
	} else {
		/* get resource */
		for( n=0 ; n<dst->rmap_no ; n++)
			if (dst->rmap[n].resource->name.len == name->len &&
			memcmp( dst->rmap[n].resource->name.s, name->s, name->len)==0)
				break;
		if (n==dst->rmap_no) {
			rpl_tree = init_mi_tree( 404, 
				MI_SSTR("Destination has no such resource"));
		} else {
			dst->rmap[n].max_load = size;
			rpl_tree = init_mi_tree( 200, MI_SSTR(MI_OK_S));
		}
	}

	lock_stop_read( ref_lock );

	return rpl_tree;
bad_syntax:
	return init_mi_tree( 400, MI_SSTR(MI_BAD_PARM_S));

}


/*! \brief
 * Expects 2 nodes: 
 *        destination ID (number)
 *        status (number)
 */

static struct mi_root* mi_lb_status(struct mi_root *cmd, void *param)
{
	struct mi_root *rpl_tree;
	struct lb_dst *dst;
	struct mi_node *node;
	unsigned int  id, stat;

	node = cmd->node.kids;
	if (node==NULL)
		return init_mi_tree( 400, MI_MISSING_PARM_S, MI_MISSING_PARM_LEN);

	/* id (param 1) */
	if (str2int( &node->value, &id) < 0)
		return init_mi_tree( 400, MI_SSTR(MI_BAD_PARM_S));

	lock_start_read( ref_lock );

	/* status (param 2) */
	node = node->next;
	if (node == NULL) {
		/* return the status -> find the destination */
		for(dst=(*curr_data)->dsts; dst && dst->id!=id ;dst=dst->next);
		if (dst==NULL) {
			rpl_tree = init_mi_tree( 404,
				MI_SSTR("Destination ID not found"));
		} else {
			rpl_tree = init_mi_tree( 200, MI_OK_S, MI_OK_LEN);
			if (rpl_tree!=NULL) {
				if (dst->flags&LB_DST_STAT_DSBL_FLAG) {
					node = add_mi_node_child( &rpl_tree->node, 0, "enable", 6,
							"no", 2);
				} else {
					node = add_mi_node_child( &rpl_tree->node, 0, "enable", 6,
							"yes", 3);
				}
				if (node==NULL) {free_mi_tree(rpl_tree); rpl_tree=NULL;}
			}
		}
	} else {
		/* set the status */
		if (node->next) {
			rpl_tree = init_mi_tree( 400,
				MI_MISSING_PARM_S, MI_MISSING_PARM_LEN);
		} else if (str2int( &node->value, &stat) < 0) {
			rpl_tree = init_mi_tree( 400, MI_SSTR(MI_BAD_PARM_S));
		} else {
			/* find the destination */
			for( dst=(*curr_data)->dsts ; dst && dst->id!=id ; dst=dst->next);
			if (dst==NULL) {
				rpl_tree =  init_mi_tree( 404,
					MI_SSTR("Destination ID not found"));
			} else {
				/* set the disable/enable */
				if (stat) {
					dst->flags &=
						~ (LB_DST_STAT_DSBL_FLAG|LB_DST_STAT_NOEN_FLAG);
				} else {
					dst->flags |= 
						LB_DST_STAT_DSBL_FLAG|LB_DST_STAT_NOEN_FLAG;
				}
				lock_stop_read( ref_lock );
				return init_mi_tree( 200, MI_OK_S, MI_OK_LEN);
			}
		}
	}

	lock_stop_read( ref_lock );

	return rpl_tree;
}




static struct mi_root* mi_lb_list(struct mi_root *cmd_tree, void *param)
{
	struct mi_root *rpl_tree;
	struct mi_node *dst_node;
	struct mi_node *node;
	struct mi_attr *attr;
	struct lb_dst *dst;
	char *p;
	int len;
	int i;

	rpl_tree = init_mi_tree( 200, MI_OK_S, MI_OK_LEN);
	if (rpl_tree==NULL)
		return NULL;

	lock_start_read( ref_lock );

	/* go through all destination */
	for( dst=(*curr_data)->dsts ; dst ; dst=dst->next) {
		/* add a destination node */
		dst_node = add_mi_node_child( &rpl_tree->node, 0, "Destination", 11,
					dst->uri.s, dst->uri.len);
		if (dst_node==0)
			goto error;

		/* add some attributes to the destination node */
		p= int2str((unsigned long)dst->id, &len);
		attr = add_mi_attr( dst_node, MI_DUP_VALUE, "id", 2, p, len);
		if (attr==0)
			goto error;

		p= int2str((unsigned long)dst->group, &len);
		attr = add_mi_attr( dst_node, MI_DUP_VALUE, "group", 5, p, len);
		if (attr==0)
			goto error;

		if (dst->flags&LB_DST_STAT_DSBL_FLAG) {
			attr = add_mi_attr( dst_node, 0, "enabled", 7, "no", 2);
		} else {
			attr = add_mi_attr( dst_node, 0, "enabled", 7, "yes", 3);
		}
		if (attr==0)
			goto error;

		if (dst->flags&LB_DST_STAT_NOEN_FLAG) {
			attr = add_mi_attr( dst_node, 0, "auto-reenable", 7, "off", 3);
		} else {
			attr = add_mi_attr( dst_node, 0, "auto-reenable", 7, "on", 2);
		}
		if (attr==0)
			goto error;

		/* go through all resources */
		for( i=0 ; i<dst->rmap_no ; i++) {
		/* add a resource node */
			node = add_mi_node_child( dst_node, 0, "Resource", 8,
				dst->rmap[i].resource->name.s,dst->rmap[i].resource->name.len);
			if (dst_node==0)
				goto error;

			/* add some attributes to the destination node */
			p= int2str((unsigned long)dst->rmap[i].max_load, &len);
			attr = add_mi_attr( node, MI_DUP_VALUE, "max", 3, p, len);
			if (attr==0)
				goto error;

			p= int2str((unsigned long)lb_dlg_binds.get_profile_size
				(dst->rmap[i].resource->profile, &dst->profile_id), &len);
			attr = add_mi_attr( node, MI_DUP_VALUE, "load", 4, p, len);
			if (attr==0)
				goto error;
		}
	}

	lock_stop_read( ref_lock );
	return rpl_tree;
error:
	lock_stop_read( ref_lock );
	free_mi_tree(rpl_tree);
	return 0;
}
