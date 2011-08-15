/*
 * $Id: val.h 5898 2009-07-20 16:41:39Z bogdan_iancu $
 *
 * Copyright (C) 2007 1&1 Internet AG
 *
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
 */

#ifndef DB_PG_VAL_H
#define DB_PG_VAL_H

int db_postgres_str2val(const db_type_t _t, db_val_t* _v, const char* _s, const int _l);

int db_postgres_val2str(const db_con_t* _con, const db_val_t* _v, char* _s, int* _len);

#endif
