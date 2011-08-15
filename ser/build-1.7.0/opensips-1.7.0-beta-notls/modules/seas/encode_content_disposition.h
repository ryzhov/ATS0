/* $Id: encode_content_disposition.h 6030 2009-08-26 22:04:18Z bogdan_iancu $
 *
 * Copyright (C) 2006-2007 VozTelecom Sistemas S.L
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


int encode_content_disposition(char *hdrstart,int hdrlen,struct disposition *body,unsigned char *where);
int print_encoded_content_disposition(FILE *fp,char *hdr,int hdrlen,unsigned char* payload,int paylen,char *prefix);
