/*
 * $Id: api.c 7358 2010-11-09 15:04:28Z vladut-paiu $
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
 * \brief OpenSIPS RR module (record-routing)
 * \ingroup rr
 */


#include "../../sr_module.h"
#include "loose.h"
#include "record.h"
#include "api.h"
#include "rr_cb.h"

extern int append_fromtag;

int load_rr( struct rr_binds *rrb )
{
	rrb->add_rr_param      = add_rr_param;
	rrb->check_route_param = check_route_param;
	rrb->is_direction      = is_direction;
	rrb->get_route_param   = get_route_param;
	rrb->register_rrcb     = register_rrcb;
	rrb->get_remote_target = get_remote_target;
	rrb->get_route_set	   = get_route_set;
	rrb->append_fromtag    = append_fromtag;
	rrb->removed_routes    = &removed_routes;
	rrb->routing_type	   = &routing_type;

	return 1;
}

