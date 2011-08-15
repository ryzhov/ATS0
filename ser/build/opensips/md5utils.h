/* 
 * $Id: md5utils.h 5902 2009-07-21 07:50:39Z bogdan_iancu $
 *
 * Copyright (C) 2007 1&1 Internet AG
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


#ifndef _MD5UTILS_H
#define _MD5UTILS_H

#include "str.h"

#define MD5_LEN	32

void MD5StringArray (char *dst, str src[], unsigned int size);

int MD5File(char *dest, const char *name);

#endif /* _MD5UTILS_H */
