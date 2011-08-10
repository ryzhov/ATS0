/*
 * $Id: script_cb.h 6117 2009-09-14 08:54:30Z bogdan_iancu $
 *
 * Copyright (C) 2001-2003 FhG Fokus
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
 *  2005-02-13  script callbacks devided into request and reply types (bogdan)
 */

/*!
 * \file
 * \brief Script callbacks
 */

#ifndef _SCRIPT_CB_H_
#define _SCRIPT_CB_H_

#include "parser/msg_parser.h"

typedef int (cb_function)( struct sip_msg *msg, void *param );


#define PRE_SCRIPT_CB    (1<<0)
#define POST_SCRIPT_CB   (1<<1)
#define REQ_TYPE_CB      (1<<2)
#define RPL_TYPE_CB      (1<<3)
#define PARSE_ERR_CB     (1<<4)


struct script_cb{
	cb_function *cbf;
	struct script_cb *next;
	unsigned int id;
	void *param;
};

int register_script_cb( cb_function f, int type, void *param );
void destroy_script_cb();

int exec_pre_req_cb( struct sip_msg *msg);
int exec_post_req_cb( struct sip_msg *msg);

int exec_pre_rpl_cb( struct sip_msg *msg);
int exec_post_rpl_cb( struct sip_msg *msg);

int exec_parse_err_cb( struct sip_msg *msg);

#endif

