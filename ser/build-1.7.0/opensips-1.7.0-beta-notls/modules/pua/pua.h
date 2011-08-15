/*
 * $Id: pua.h 6722 2010-03-15 11:25:23Z anca_vamanu $
 *
 * pua module - presence user agent module
 *
 * Copyright (C) 2006 Voice Sistem S.R.L.
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

#ifndef PUBLISH_H
#define PUBLISH_H

#include "../../str.h"
#include "hash.h"
#include "../../db/db.h"

#define INSERT_TYPE      1<<1
#define UPDATE_TYPE      1<<2

#define REQ_OTHER  0
#define REQ_ME     1

extern str default_domain;
extern struct tm_binds tmb;
extern htable_t* HashT;
extern int HASH_SIZE;
extern int min_expires;
extern int pua_ul_publish;
extern int default_expires;
extern db_con_t *pua_db;
extern db_func_t pua_dbf;
extern str db_table;
#endif
