/*
 * $Id: prefix_tree.h 7243 2010-09-28 10:49:54Z razvancrainea $
 *
 * Copyright (C) 2005-2008 Voice Sistem SRL
 *
 * This file is part of Open SIP Server (OpenSIPS).
 *
 * DROUTING OpenSIPS-module is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * DROUTING OpenSIPS-module is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * For any questions about this software and its license, please contact
 * Voice Sistem at following e-mail address:
 *         office@voice-system.ro
 *
 * History:
 * ---------
 *  2005-02-20  first version (cristian)
 *  2005-02-27  ported to 0.9.0 (bogdan)
 */



#ifndef prefix_tree_h
#define prefix_tree_h

#include "../../str.h"
#include "../../ip_addr.h"
#include "../../time_rec.h"

#define PTREE_CHILDREN 10
#define IS_DECIMAL_DIGIT(d) \
	(((d)>='0') && ((d)<= '9'))

extern int tree_size;

#define INIT_PTREE_NODE(p, n) \
do {\
	(n) = (ptree_t*)shm_malloc(sizeof(ptree_t));\
	if(NULL == (n))\
		goto err_exit;\
	tree_size+=sizeof(ptree_t);\
	memset((n), 0, sizeof(ptree_t));\
	(n)->bp=(p);\
}while(0);


#define DR_DST_PING_DSBL_FLAG   (1<<0)
#define DR_DST_PING_PERM_FLAG   (1<<1)
#define DR_DST_STAT_DSBL_FLAG   (1<<2)
#define DR_DST_STAT_NOEN_FLAG   (1<<3)

#define DR_MAX_IPS  32

/* list of PSTN gw */
typedef struct pgw_ {
	/* id matching the one in db */
	unsigned int id;
	int type;
	str ip_str;
	/* strip / pri and attrs */
	str pri;
	int strip;
	str attrs;
	/* addres and port */
	struct ip_addr ips[DR_MAX_IPS];
	unsigned short ips_no;
	unsigned short port;
	struct pgw_ *next;
	int flags;
}pgw_t;

/**/
typedef struct pgw_list_ {
	pgw_t *pgw;
	int    grpid;
}pgw_list_t;

/* element containing routing information */
typedef struct rt_info_ {
	/* id matching the one in db */
	unsigned int id;
	unsigned int priority;
	tmrec_t *time_rec;
	/* array of pointers into the PSTN gw list */
	pgw_list_t *pgwl;
	/* length of the PSTN gw array */
	unsigned short pgwa_len;
	/* how many list link this element */
	unsigned short ref_cnt;
	/* script route to be executed */
	int route_idx;
	str attrs;
} rt_info_t;

typedef struct rt_info_wrp_ {
	rt_info_t     *rtl;
	struct rt_info_wrp_  *next;
} rt_info_wrp_t;

typedef struct rg_entry_ {
	unsigned int rgid;
	rt_info_wrp_t *rtlw;
} rg_entry_t;

typedef struct ptree_node_ {
	unsigned int rg_len;
	unsigned int rg_pos;
	rg_entry_t *rg;
	struct ptree_ *next;
} ptree_node_t;

typedef struct ptree_ {
	/* backpointer */
	struct ptree_ *bp;
	ptree_node_t ptnode[PTREE_CHILDREN];
} ptree_t;

void 
print_interim(
		int,
		int,
		ptree_t*
		);

int
del_tree(
	ptree_t *
	);

int
add_prefix(
	ptree_t*,
	/* prefix */
	str*,
	rt_info_t *,
	unsigned int
	);

rt_info_t*
get_prefix(
	ptree_t *ptree,
	str* prefix,
	unsigned int rgid
	);

int
add_rt_info(
	ptree_node_t*, 
	rt_info_t*,
	unsigned int
	);

pgw_t*
get_pgw(
	pgw_t*,
	long
	);

void
del_rt_list(
	rt_info_wrp_t *rl
	);

void print_rt(
	rt_info_t*
	);

void
free_rt_info(
	rt_info_t*
	);

rt_info_t*
check_rt(
	ptree_node_t *ptn,
	unsigned int rgid
	);

#endif
