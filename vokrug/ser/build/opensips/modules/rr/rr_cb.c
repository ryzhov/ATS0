/*
 * $Id: rr_cb.c 5901 2009-07-21 07:45:05Z bogdan_iancu $
 *
 * Copyright (C) 2005 Voice Sistem SRL
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * opensips is distributed in the hope that it will be useful,
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
 *  2005-08-02  first version (bogdan)
 */

/*!
 * \file
 * \brief Route & Record-Route module, callback API
 * \ingroup rr
 */

#include "../../mem/mem.h"
#include "rr_cb.h"


struct rr_callback* rrcb_hl = 0;  /* head list */



void destroy_rrcb_lists(void)
{
	struct rr_callback *cbp, *cbp_tmp;

	for( cbp=rrcb_hl; cbp ; ) {
		cbp_tmp = cbp;
		cbp = cbp->next;
		pkg_free( cbp_tmp );
	}
}


int register_rrcb( rr_cb_t f, void *param )
{
	struct rr_callback *cbp;

	/* build a new callback structure */
	if (!(cbp=pkg_malloc( sizeof( struct rr_callback)))) {
		LM_ERR("no more pkg mem\n");
		return -1;
	}

	/* fill it up */
	cbp->callback = f;
	cbp->param = param;
	/* link it at the beginning of the list */
	cbp->next = rrcb_hl;
	rrcb_hl = cbp;
	/* set next id */
	if (cbp->next)
		cbp->id = cbp->next->id+1;
	else
		cbp->id = 0;

	return 0;
}


void run_rr_callbacks( struct sip_msg *req, str *rr_params )
{
	str l_param;
	struct rr_callback *cbp;

	for ( cbp=rrcb_hl ; cbp ; cbp=cbp->next ) {
		l_param = *rr_params;
		LM_DBG("callback id %d entered with <%.*s>\n",
			cbp->id , l_param.len,l_param.s);
		cbp->callback( req, &l_param, cbp->param );
	}
}



