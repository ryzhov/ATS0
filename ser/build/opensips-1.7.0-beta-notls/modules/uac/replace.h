/*
 * $Id: replace.h 6013 2009-08-22 20:33:44Z bogdan_iancu $
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
 *  2009-08-22  TO header replacement added (bogdan)
 */


#ifndef _UAC_REPLACE_H_
#define _UAC_REPLACE_H_

#include "../../parser/msg_parser.h"
#include "../../str.h"
#include "../tm/t_hooks.h"

#define UAC_NO_RESTORE      (0)
#define UAC_AUTO_RESTORE    (1)
#define UAC_MANUAL_RESTORE  (2)

void init_from_replacer();

int replace_uri( struct sip_msg *msg, str *display, str *uri,
		struct hdr_field *hdr, str *rr_param);

int restore_uri( struct sip_msg *msg, str *rr_param, int check_from);

/* RR callback functions */
void rr_checker(struct sip_msg *msg, str *r_param, void *cb_param);


#endif
