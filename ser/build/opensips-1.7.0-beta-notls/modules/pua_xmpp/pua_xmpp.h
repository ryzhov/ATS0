/*
 * $Id: pua_xmpp.h 6705 2010-03-10 16:37:55Z anca_vamanu $
 *
 * pua_xmpp module - presence SIP - XMPP Gateway
 *
 * Copyright (C) 2007 Voice Sistem S.R.L.
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
 *  2007-03-29  initial version (anca)
 */

#ifndef _XMMPP_TO_SIP_
#define _XMMPP_TO_SIP_

#include "../pua/pidf.h"
#include "../pua/pua_bind.h"
#include "../xmpp/xmpp_api.h"

extern str server_address;
extern str presence_server;

extern send_subscribe_t pua_send_subscribe;
extern send_publish_t pua_send_publish;
extern query_dialog_t pua_is_dialog;

extern xmpp_send_xsubscribe_f xmpp_subscribe;
extern xmpp_send_xnotify_f xmpp_notify;
extern xmpp_send_xpacket_f xmpp_packet;
extern uri_xmpp2sip_f xmpp_uri_xmpp2sip;
extern uri_sip2xmpp_f xmpp_uri_sip2xmpp;

extern xmlNodeGetAttrContentByName_t XMLNodeGetAttrContentByName;
extern xmlDocGetNodeByName_t XMLDocGetNodeByName;
extern xmlNodeGetNodeByName_t XMLNodeGetNodeByName;
extern xmlNodeGetNodeContentByName_t XMLNodeGetNodeContentByName;

#endif
