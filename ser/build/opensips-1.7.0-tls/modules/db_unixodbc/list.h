/* 
 * $Id: list.h 5901 2009-07-21 07:45:05Z bogdan_iancu $ 
 *
 * UNIXODBC module
 *
 * Copyright (C) 2005-2006 Marco Lorrai
 * Copyright (C) 2008 1&1 Internet AG
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
 *
 * History:
 * --------
 *  2005-12-01  initial commit (chgen)
 *  2006-04-04  simplified link list (sgupta)
 *  2006-05-05  removed static allocation of 1k per column data (sgupta)
 */

#ifndef _UNIXODBC_LIST_H_
#define _UNIXODBC_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "con.h"

typedef struct list
{
	struct list* next;
	char** data;
	unsigned long* lengths;
	int rownum;
} list;

int db_unixodbc_list_insert(list** start, list** link, int n, strn* value);
void db_unixodbc_list_destroy(list* link);

#endif
