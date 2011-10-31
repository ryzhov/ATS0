/*
 * $Id: config.h 5896 2009-07-20 14:37:03Z bogdan_iancu $
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


#ifndef _TM_CONFIG_H
#define _TM_CONFIG_H

/* hash table engine and hash function
*/
#include "../../hash_func.h"
#include "../../config.h"


/* size of TM hash table */
#define TM_TABLE_ENTRIES     (1<<16)

/* always use a power of 2 for hash table size */
#define tm_hash( s1, s2 )     core_hash( &s1, &s2, TM_TABLE_ENTRIES)

/* maximum length of localy generated acknowledgment */
#define MAX_ACK_LEN   1024

/* FINAL_RESPONSE_TIMER ... tells how long should the transaction engine
   wait if no final response comes back*/
#define FR_TIME_OUT       30
#define INV_FR_TIME_OUT   120

/* WAIT timer ... tells how long state should persist in memory after
   a transaction was finalized*/
#define WT_TIME_OUT       5

/* DELETE timer ... tells how long should the transaction persist in memory
   after it was removed from the hash table and before it will be deleted */
#define DEL_TIME_OUT      2
 
/* retransmission timers */
#define RETR_T1           500        /* in milliseconds */
#define RETR_T2           4000       /* in milliseconds */

/* when first reply is sent, this additional space is allocated so that
   one does not have to reallocate share memory when the message is
   replaced by a subsequent, longer message
*/
#define REPLY_OVERBUFFER_LEN 160
#define TAG_OVERBUFFER_LEN 32

/* dimensions of FIFO server */
#define MAX_METHOD	64
#define MAX_HEADER	1024
#define MAX_BODY	1024
#define MAX_DST	512
#define MAX_FROM 512

/* messages generated by server */
#define CANCELING "canceling"
#define CANCEL_DONE "ok -- no more pending branches"
#define CANCELED "Request canceled"

/* to-tag separator for stateful processing */
#define TM_TAG_SEPARATOR '-'

/* FIFO substitution character */
#define SUBST_CHAR '!'

#endif
