/*
 * $Id: sst.c 6910 2010-05-26 09:23:27Z bogdan_iancu $
 *
 * SIP Session Timer (sst) module - support for tracking dialogs and
 * SIP Session Timers.
 *
 * Copyright (C) 2006 SOMA Networks, INC.
 * Written by: Ron Winacott (karwin)
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 *
 * History:
 * --------
 * 2006-05-11 initial version (karwin)
 * 2006-10-10 RFC compilent changes. Added the other flags (karwin)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../sr_module.h"
#include "../signaling/signaling.h"
#include "sst_handlers.h" /* also includes sr_module.h needed by
                             handlers */



static int mod_init(void);


/** SIGNALING binds */
struct sig_binds sigb;

/*
 * statistic variables 
 */
int sst_enable_stats = 1;
stat_var *expired_sst = 0;

/*
 * The name of the AVP the dialog module will use to hold the timeout
 * value so we can set the AVP in the dialog callbacks so the dialog
 * code will set the dialog lifetime when it returns from the INVITE
 * and IN_ROUTE callbacks.
 */
pv_spec_t timeout_avp; 
static char* timeout_spec = 0; /* Place holder for the passed in name */

/*
 * The default or script parameter for the requested MIN-SE: value for
 * this proxy. (in seconds) If the passed in value is 0, then this
 * proxy will except any value from the UAC as its min-SE value. If
 * the value is NOT set then the default will be asserted.
 */
unsigned int sst_minSE = 90; 

/*
 * Should the PROXY (us) reject (with a 422 reply) and SE < sst_minSE
 * requests is it can. Default is YES.
 */
unsigned int sst_reject = 1;

/* The sst message flag value */
static int sst_flag = -1;

/* 
 * The sst minimum interval in Session-Expires header if OpenSIPS
 * request the use of session times. The used value will be the
 * maximum value between OpenSIPS minSE, UAS minSE and this value
*/ 
unsigned int sst_interval = 0;

/*
 * Binding to the dialog module
 */
struct dlg_binds dialog_st;
struct dlg_binds *dlg_binds = &dialog_st;

/*
 * Script commands we export.
 */
static cmd_export_t cmds[]={
	{"sstCheckMin", (cmd_function)sst_check_min, 1, 0, 0, REQUEST_ROUTE | ONREPLY_ROUTE },
	{0,0,0,0,0,0}
};

/*
 * Script parameters
 */
static param_export_t mod_params[]={
	{ "enable_stats", INT_PARAM, &sst_enable_stats		},
	{ "min_se", INT_PARAM, &sst_minSE					},
	{ "timeout_avp", STR_PARAM, &timeout_spec			},
	{ "reject_to_small",		INT_PARAM, &sst_reject 	},
	{ "sst_flag",				INT_PARAM, &sst_flag	},
	{ "sst_interval",		INT_PARAM, &sst_interval	},
	{ 0,0,0 }
};

/*
 * Export the statistics we have
 */
static stat_export_t mod_stats[] = {
	{"expired_sst", 0,  &expired_sst},
	{0,0,0}
};

struct module_exports exports= {
	"sst",        /* module's name */
	MODULE_VERSION,
	DEFAULT_DLFLAGS, /* dlopen flags */
	cmds,         /* exported functions */
	mod_params,   /* param exports */
	mod_stats,    /* exported statistics */
	0,            /* exported MI functions */
	0,            /* exported pseudo-variables */
	0,            /* extra processes */
	mod_init,     /* module initialization function */
	0,            /* reply processing function */
	0,            /* Destroy function */
	0             /* per-child init function */
};

/**
 * The initialization function, called when the module is loaded by
 * the script. This function is called only once.
 *
 * Bind to the dialog module and setup the callbacks. Also initialize
 * the shared memory to store our interninal information in.
 *
 * @return 0 to continue to load the OpenSIPS, -1 to stop the loading
 * and abort OpenSIPS.
 */
static int mod_init(void) 
{
	str s;
	LM_INFO("SIP Session Timer module - initializing\n");
	/*
	 * if statistics are disabled, prevent their registration to core.
	 */
	if (sst_enable_stats==0) {
		exports.stats = 0;
	}

	if (sst_flag == -1) {
		LM_ERR("no sst flag set!!\n");
		return -1;
	} 
	else if (sst_flag > MAX_FLAG) {
		LM_ERR("invalid sst flag %d!!\n", sst_flag);
		return -1;
	}

	if (timeout_spec != NULL) {
		LM_DBG("Dialog AVP is %s", timeout_spec);
		s.s = timeout_spec; s.len = strlen(s.s);
		if (pv_parse_spec(&s, &timeout_avp)==0 
		&& (timeout_avp.type != PVT_AVP)){
			LM_ERR("malformed or non AVP timeout AVP definition in '%s'\n",
					timeout_spec);
			return -1;
		}
	}

	/* load SIGNALING API */
	if(load_sig_api(&sigb)< 0) {
		LM_ERR("can't load signaling functions\n");
		return -1;
	}

	/*
	 * Init the handlers
	 */
	sst_handler_init((timeout_spec?&timeout_avp:0), sst_minSE, 
			sst_flag, sst_reject,sst_interval);

	/*
	 * Register the main (static) dialog call back.
	 */
	if (load_dlg_api(&dialog_st) != 0) {
		LM_ERR("failed to load dialog hooks");
		return(-1);
	}

	/* Load dialog hooks */
	dialog_st.register_dlgcb(NULL, DLGCB_CREATED, sst_dialog_created_CB, NULL, NULL);

	/*
	 * We are GOOD-TO-GO.
	 */
	return 0;
}
