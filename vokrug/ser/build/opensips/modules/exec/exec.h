/*
 *
 * $Id: exec.h 5901 2009-07-21 07:45:05Z bogdan_iancu $
 *
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
 */

#ifndef _EXEC_H
#define _EXEC_H

#include "../../pvar.h"

int exec_str(struct sip_msg *msg, char *cmd, char *param, int param_len);
int exec_msg(struct sip_msg *msg, char *cmd );
int exec_avp(struct sip_msg *msg, char *cmd, pvname_list_p avpl);
int exec_getenv(struct sip_msg *msg, char *cmd, pvname_list_p avpl);

#endif
