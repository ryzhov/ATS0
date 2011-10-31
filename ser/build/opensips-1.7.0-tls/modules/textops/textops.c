/*$Id: textops.c 8301 2011-08-24 09:25:08Z bogdan_iancu $
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
 *
 *
 * History:
 * -------
 *  2003-02-28  scratchpad compatibility abandoned (jiri)
 *  2003-01-29: - rewriting actions (replace, search_append) now begin
 *                at the second line -- previously, they could affect
 *                first line too, which resulted in wrong calculation of
 *                forwarded requests and an error consequently
 *              - replace_all introduced
 *  2003-01-28  scratchpad removed (jiri)
 *  2003-01-18  append_urihf introduced (jiri)
 *  2003-03-10  module export interface updated to the new format (andrei)
 *  2003-03-16  flags export parameter added (janakj)
 *  2003-03-19  replaced all mallocs/frees w/ pkg_malloc/pkg_free (andrei)
 *  2003-04-97  actions permitted to be used from failure/reply routes (jiri)
 *  2003-04-21  remove_hf and is_present_hf introduced (jiri)
 *  2003-08-19  subst added (support for sed like res:s/re/repl/flags) (andrei)
 *  2003-08-20  subst_uri added (like above for uris) (andrei)
 *  2003-09-11  updated to new build_lump_rpl() interface (bogdan)
 *  2003-11-11: build_lump_rpl() removed, add_lump_rpl() has flags (bogdan)
 *  2004-05-09: append_time introduced (jiri)
 *  2004-07-06  subst_user added (like subst_uri but only for user) (sobomax)
 *  2004-11-12  subst_user changes (old serdev mails) (andrei)
 *  2005-07-05  is_method("name") to check method using id (ramona)
 *  2006-03-17  applied patch from Marc Haisenko <haisenko@comdasys.com> 
 *              for adding has_body() function (bogdan)
 *  2009-07-23  added methods for sdp codec manipulation(andreidragus)
 *
 */


#include "../../sr_module.h"
#include "../../action.h"
#include "../../dprint.h"
#include "../../data_lump.h"
#include "../../data_lump_rpl.h"
#include "../../error.h"
#include "../../mem/mem.h"
#include "../../mem/shm_mem.h"
#include "../../str.h"
#include "../../re.h"
#include "../../mod_fix.h"
#include "../../parser/parse_uri.h"
#include "../../parser/parse_hname2.h"
#include "../../parser/parse_methods.h"
#include "../../parser/parse_content.h"
#include "../../parser/parse_privacy.h"
#include "../../parser/sdp/sdp.h"
#include "../../mod_fix.h"

#include"codecs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> /* for regex */
#include <regex.h>
#include <time.h>
#include <sys/time.h>




/* RFC822-conforming dates format:

   %a -- abbreviated week of day name (locale), %d day of month
   as decimal number, %b abbreviated month name (locale), %Y
   year with century, %T time in 24h notation
*/
#define TIME_FORMAT "Date: %a, %d %b %Y %H:%M:%S GMT"
#define MAX_TIME 64

#define AUDIO_STR "audio"
#define AUDIO_STR_LEN 5

static int search_f(struct sip_msg*, char*, char*);
static int search_body_f(struct sip_msg*, char*, char*);
static int replace_f(struct sip_msg*, char*, char*);
static int replace_body_f(struct sip_msg*, char*, char*);
static int replace_all_f(struct sip_msg*, char*, char*);
static int replace_body_all_f(struct sip_msg*, char*, char*);
static int replace_body_atonce_f(struct sip_msg*, char*, char*);
static int subst_f(struct sip_msg*, char*, char*);
static int subst_uri_f(struct sip_msg*, char*, char*);
static int subst_user_f(struct sip_msg*, char*, char*);
static int subst_body_f(struct sip_msg*, char*, char*);
static int filter_body_f(struct sip_msg*, char*, char*);
static int remove_hf_f(struct sip_msg* msg, char* str_hf, char* foo);
static int is_present_hf_f(struct sip_msg* msg, char* str_hf, char* foo);
static int search_append_f(struct sip_msg*, char*, char*);
static int search_append_body_f(struct sip_msg*, char*, char*);
static int append_to_reply_f(struct sip_msg* msg, char* key, char* str);
static int append_hf_1(struct sip_msg* msg, char* str1, char* str2);
static int append_hf_2(struct sip_msg* msg, char* str1, char* str2);
static int insert_hf_1(struct sip_msg* msg, char* str1, char* str2);
static int insert_hf_2(struct sip_msg* msg, char* str1, char* str2);
static int append_urihf(struct sip_msg* msg, char* str1, char* str2);
static int append_time_f(struct sip_msg* msg, char* , char *);
static int is_method_f(struct sip_msg* msg, char* , char *);
static int has_body_f(struct sip_msg *msg, char *type, char *str2 );
static int is_privacy_f(struct sip_msg *msg, char *privacy, char *str2 );
static int strip_body_f(struct sip_msg *msg, char *str1, char *str2 );
static int strip_body_f2(struct sip_msg *msg, char *str1, char *str2 );
static int add_body_f_1(struct sip_msg *msg, char *str1, char *str2 );
static int add_body_f_2(struct sip_msg *msg, char *str1, char *str2 );
static int is_audio_on_hold_f(struct sip_msg *msg, char *str1, char *str2 );

static int fixup_substre(void**, int);
static int hname_fixup(void** param, int param_no);
static int free_hname_fixup(void** param, int param_no);
static int fixup_method(void** param, int param_no);
static int add_header_fixup(void** param, int param_no);
static int fixup_body_type(void** param, int param_no);
static int fixup_privacy(void** param, int param_no);


static int mod_init(void);


static cmd_export_t cmds[]={
	{"search",           (cmd_function)search_f,          1,
		fixup_regexp_null, fixup_free_regexp_null,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"search_body",      (cmd_function)search_body_f,     1,
		fixup_regexp_null, fixup_free_regexp_null,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"search_append",    (cmd_function)search_append_f,   2,
		fixup_regexp_none,fixup_free_regexp_none,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"search_append_body", (cmd_function)search_append_body_f,   2,
		fixup_regexp_none, fixup_free_regexp_none, 
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"replace",          (cmd_function)replace_f,         2,
		fixup_regexp_none, fixup_free_regexp_none,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"replace_body",     (cmd_function)replace_body_f,    2,
		fixup_regexp_none, fixup_free_regexp_none,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"replace_all",      (cmd_function)replace_all_f,     2,
		fixup_regexp_none, fixup_free_regexp_none,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"replace_body_all", (cmd_function)replace_body_all_f,2,
		fixup_regexp_none, fixup_free_regexp_none,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"replace_body_atonce", (cmd_function)replace_body_atonce_f,2,
		fixup_regexpNL_none, fixup_free_regexp_none,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"append_to_reply",  (cmd_function)append_to_reply_f, 1,
		fixup_spve_null, 0,
		REQUEST_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|ERROR_ROUTE},
	{"append_hf",        (cmd_function)append_hf_1,       1,
		add_header_fixup, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"append_hf",        (cmd_function)append_hf_2,       2,
		add_header_fixup, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"insert_hf",        (cmd_function)insert_hf_1,       1, 
		add_header_fixup, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"insert_hf",        (cmd_function)insert_hf_2,       2, 
		add_header_fixup, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"append_urihf",     (cmd_function)append_urihf,      2,
		fixup_str_str, fixup_free_str_str,
		REQUEST_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE},
	{"remove_hf",        (cmd_function)remove_hf_f,       1,
		hname_fixup, free_hname_fixup,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"is_present_hf",    (cmd_function)is_present_hf_f,   1,
		hname_fixup, free_hname_fixup,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"subst",            (cmd_function)subst_f,           1,
		fixup_substre, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"subst_uri",        (cmd_function)subst_uri_f,       1,
		fixup_substre, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE},
	{"subst_user",       (cmd_function)subst_user_f,      1,
		fixup_substre, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE},
	{"subst_body",       (cmd_function)subst_body_f,      1,
		fixup_substre, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"filter_body",      (cmd_function)filter_body_f,     1,
		fixup_str_null, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"append_time",      (cmd_function)append_time_f,     0,
		0, 0,
		REQUEST_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE },
	{"is_method",        (cmd_function)is_method_f,       1,
		fixup_method, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"has_body",         (cmd_function)has_body_f,        0,
		0, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"has_body",         (cmd_function)has_body_f,        1, 
		fixup_body_type, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"is_privacy",       (cmd_function)is_privacy_f,      1,
		fixup_privacy, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"strip_body",      (cmd_function)strip_body_f,     0,
		0, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE },
	{"strip_body",      (cmd_function)strip_body_f2,     1,
		fixup_body_type, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE },
	{"add_body",         (cmd_function)add_body_f_1,        1, 
		fixup_spve_null, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"add_body",         (cmd_function)add_body_f_2,        2, 
		add_header_fixup, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"codec_exists",	(cmd_function)codec_find,	1,
		fixup_codec,0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"codec_exists_re",	(cmd_function)codec_find_re,	1,
		fixup_codec_regexp, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"codec_exists",	(cmd_function)codec_find_clock,	2,
		fixup_codec,0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"codec_delete",	(cmd_function)codec_delete,	1,
		fixup_codec,0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"codec_delete_re",	(cmd_function)codec_delete_re,	1,
		fixup_codec_regexp, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"codec_delete_except_re",	(cmd_function)codec_delete_except_re,	1,
		fixup_codec_regexp, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"codec_delete",	(cmd_function)codec_delete_clock, 2,
		fixup_codec,0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"codec_move_up",	(cmd_function)codec_move_up, 1,
		fixup_codec,0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"codec_move_up_re",	(cmd_function)codec_move_up_re, 1,
		fixup_codec_regexp,0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"codec_move_up",	(cmd_function)codec_move_up_clock, 2,
		fixup_codec,0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"codec_move_down",	(cmd_function)codec_move_down,	1,
		fixup_codec,0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"codec_move_down_re",	(cmd_function)codec_move_down_re,	1,
		fixup_codec_regexp,0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"codec_move_down",	(cmd_function)codec_move_down_clock,	2,
		fixup_codec,0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},
	{"is_audio_on_hold",    (cmd_function)is_audio_on_hold_f,       0,
		0, 0,
		REQUEST_ROUTE|ONREPLY_ROUTE|FAILURE_ROUTE|BRANCH_ROUTE|LOCAL_ROUTE},

	{0,0,0,0,0,0}
};


struct module_exports exports= {
	"textops",  /* module name*/
	MODULE_VERSION,
	DEFAULT_DLFLAGS, /* dlopen flags */
	cmds,       /* exported functions */
	0,          /* module parameters */
	0,          /* exported statistics */
	0,          /* exported MI functions */
	0,          /* exported pseudo-variables */
	0,          /* extra processes */
	mod_init,   /* module initialization function */
	0,          /* response function */
	0,          /* destroy function */
	0,          /* per-child init function */
};


static int mod_init(void)
{
	LM_INFO("initializing...\n");
	return 0;
}

static char *get_header(struct sip_msg *msg)
{
	return msg->buf+msg->first_line.len;
}



static int search_f(struct sip_msg* msg, char* key, char* str2)
{
	/*we registered only 1 param, so we ignore str2*/
	regmatch_t pmatch;

	if (regexec((regex_t*) key, msg->buf, 1, &pmatch, 0)!=0) return -1;
	return 1;
}


static int search_body_f(struct sip_msg* msg, char* key, char* str2)
{
	str body;
	/*we registered only 1 param, so we ignore str2*/
	regmatch_t pmatch;

	body.s = get_body(msg);
	if (body.s==0) {
		LM_ERR("failed to get the message body\n");
		return -1;
	}
	body.len = msg->len -(int)(body.s-msg->buf);
	if (body.len==0) {
		LM_DBG("message body has zero length\n");
		return -1;
	}

	if (regexec((regex_t*) key, body.s, 1, &pmatch, 0)!=0) return -1;
	return 1;
}


static int search_append_f(struct sip_msg* msg, char* key, char* str2)
{
	struct lump* l;
	regmatch_t pmatch;
	char* s;
	int len;
	char *begin;
	int off;

	begin=get_header(msg); /* msg->orig/buf previously .. uri problems */
	off=begin-msg->buf;

	if (regexec((regex_t*) key, begin, 1, &pmatch, 0)!=0) return -1;
	if (pmatch.rm_so!=-1){
		if ((l=anchor_lump(msg, off+pmatch.rm_eo, 0, 0))==0)
			return -1;
		len=strlen(str2);
		s=pkg_malloc(len);
		if (s==0){
			LM_ERR("memory allocation failure\n");
			return -1;
		}
		memcpy(s, str2, len); 
		if (insert_new_lump_after(l, s, len, 0)==0){
			LM_ERR("could not insert new lump\n");
			pkg_free(s);
			return -1;
		}
		return 1;
	}
	return -1;
}

static int search_append_body_f(struct sip_msg* msg, char* key, char* str2)
{
	struct lump* l;
	regmatch_t pmatch;
	char* s;
	int len;
	int off;
	str body;

	body.s = get_body(msg);
	if (body.s==0) {
		LM_ERR("failed to get the message body\n");
		return -1;
	}
	body.len = msg->len -(int)(body.s-msg->buf);
	if (body.len==0) {
		LM_DBG("message body has zero length\n");
		return -1;
	}

	off=body.s-msg->buf;

	if (regexec((regex_t*) key, body.s, 1, &pmatch, 0)!=0) return -1;
	if (pmatch.rm_so!=-1){
		if ((l=anchor_lump(msg, off+pmatch.rm_eo, 0, 0))==0)
			return -1;
		len=strlen(str2);
		s=pkg_malloc(len);
		if (s==0){
			LM_ERR("memory allocation failure\n");
			return -1;
		}
		memcpy(s, str2, len); 
		if (insert_new_lump_after(l, s, len, 0)==0){
			LM_ERR("could not insert new lump\n");
			pkg_free(s);
			return -1;
		}
		return 1;
	}
	return -1;
}


static int replace_all_f(struct sip_msg* msg, char* key, char* str2)
{
	struct lump* l;
	regmatch_t pmatch;
	char* s;
	int len;
	char* begin;
	int off;
	int ret;
	int eflags;

	begin = get_header(msg);
	ret=-1; /* pessimist: we will not find any */
	len=strlen(str2);
	eflags=0; /* match ^ at the beginning of the string*/

	while (begin<msg->buf+msg->len 
				&& regexec((regex_t*) key, begin, 1, &pmatch, eflags)==0) {
		off=begin-msg->buf;
		if (pmatch.rm_so==-1){
			LM_ERR("offset unknown\n");
			return -1;
		}
		if (pmatch.rm_so==pmatch.rm_eo){
			LM_ERR("matched string is empty... invalid regexp?\n");
			return -1;
		}
		if ((l=del_lump(msg, pmatch.rm_so+off,
						pmatch.rm_eo-pmatch.rm_so, 0))==0) {
			LM_ERR("del_lump failed\n");
			return -1;
		}
		s=pkg_malloc(len);
		if (s==0){
			LM_ERR("memory allocation failure\n");
			return -1;
		}
		memcpy(s, str2, len); 
		if (insert_new_lump_after(l, s, len, 0)==0){
			LM_ERR("could not insert new lump\n");
			pkg_free(s);
			return -1;
		}
		/* new cycle */
		begin=begin+pmatch.rm_eo;
		/* is it still a string start */
		if (*(begin-1)=='\n' || *(begin-1)=='\r')
			eflags&=~REG_NOTBOL;
		else
			eflags|=REG_NOTBOL;
		ret=1;
	} /* while found ... */
	return ret;
}

static int do_replace_body_f(struct sip_msg* msg, char* key, char* str2, int nobol)
{
	struct lump* l;
	regmatch_t pmatch;
	char* s;
	int len;
	char* begin;
	int off;
	int ret;
	int eflags;
	str body;

	body.s = get_body(msg);
	if (body.s==0) {
		LM_ERR("failed to get the message body\n");
		return -1;
	}
	body.len = msg->len -(int)(body.s-msg->buf);
	if (body.len==0) {
		LM_DBG("message body has zero length\n");
		return -1;
	}

	begin=body.s;
	ret=-1; /* pessimist: we will not find any */
	len=strlen(str2);
	eflags=0; /* match ^ at the beginning of the string*/

	while (begin<msg->buf+msg->len 
				&& regexec((regex_t*) key, begin, 1, &pmatch, eflags)==0) {
		off=begin-msg->buf;
		if (pmatch.rm_so==-1){
			LM_ERR("offset unknown\n");
			return -1;
		}
		if (pmatch.rm_so==pmatch.rm_eo){
			LM_ERR("matched string is empty... invalid regexp?\n");
			return -1;
		}
		if ((l=del_lump(msg, pmatch.rm_so+off,
						pmatch.rm_eo-pmatch.rm_so, 0))==0) {
			LM_ERR("del_lump failed\n");
			return -1;
		}
		s=pkg_malloc(len);
		if (s==0){
			LM_ERR("memory allocation failure\n");
			return -1;
		}
		memcpy(s, str2, len); 
		if (insert_new_lump_after(l, s, len, 0)==0){
			LM_ERR("could not insert new lump\n");
			pkg_free(s);
			return -1;
		}
		/* new cycle */
		begin=begin+pmatch.rm_eo;
		/* is it still a string start */
		if (nobol && (*(begin-1)=='\n' || *(begin-1)=='\r'))
			eflags&=~REG_NOTBOL;
		else
			eflags|=REG_NOTBOL;
		ret=1;
	} /* while found ... */
	return ret;
}

static int replace_body_all_f(struct sip_msg* msg, char* key, char* str2)
{
	return do_replace_body_f(msg, key, str2, 1);
}

static int replace_body_atonce_f(struct sip_msg* msg, char* key, char* str2)
{
	return do_replace_body_f(msg, key, str2, 0);
}

static int replace_f(struct sip_msg* msg, char* key, char* str2)
{
	struct lump* l;
	regmatch_t pmatch;
	char* s;
	int len;
	char* begin;
	int off;

	begin=get_header(msg); /* msg->orig previously .. uri problems */

	if (regexec((regex_t*) key, begin, 1, &pmatch, 0)!=0) return -1;
	off=begin-msg->buf;

	if (pmatch.rm_so!=-1){
		if ((l=del_lump(msg, pmatch.rm_so+off,
						pmatch.rm_eo-pmatch.rm_so, 0))==0)
			return -1;
		len=strlen(str2);
		s=pkg_malloc(len);
		if (s==0){
			LM_ERR("memory allocation failure\n");
			return -1;
		}
		memcpy(s, str2, len); 
		if (insert_new_lump_after(l, s, len, 0)==0){
			LM_ERR("could not insert new lump\n");
			pkg_free(s);
			return -1;
		}
		
		return 1;
	}
	return -1;
}

static int replace_body_f(struct sip_msg* msg, char* key, char* str2)
{
	struct lump* l;
	regmatch_t pmatch;
	char* s;
	int len;
	char* begin;
	int off;
	str body;

	body.s = get_body(msg);
	if (body.s==0) {
		LM_ERR("failed to get the message body\n");
		return -1;
	}
	body.len = msg->len -(int)(body.s-msg->buf);
	if (body.len==0) {
		LM_DBG("message body has zero length\n");
		return -1;
	}

	begin=body.s; /* msg->orig previously .. uri problems */

	if (regexec((regex_t*) key, begin, 1, &pmatch, 0)!=0) return -1;
	off=begin-msg->buf;

	if (pmatch.rm_so!=-1){
		if ((l=del_lump(msg, pmatch.rm_so+off,
						pmatch.rm_eo-pmatch.rm_so, 0))==0)
			return -1;
		len=strlen(str2);
		s=pkg_malloc(len);
		if (s==0){
			LM_ERR("memory allocation failure\n");
			return -1;
		}
		memcpy(s, str2, len); 
		if (insert_new_lump_after(l, s, len, 0)==0){
			LM_ERR("could not insert new lump\n");
			pkg_free(s);
			return -1;
		}
		
		return 1;
	}
	return -1;
}


/* sed-perl style re: s/regular expression/replacement/flags */
static int subst_f(struct sip_msg* msg, char*  subst, char* ignored)
{
	struct lump* l;
	struct replace_lst* lst;
	struct replace_lst* rpl;
	char* begin;
	struct subst_expr* se;
	int off;
	int ret;
	int nmatches;
	
	se=(struct subst_expr*)subst;
	begin=get_header(msg);  /* start after first line to avoid replacing
							   the uri */
	off=begin-msg->buf;
	ret=-1;
	if ((lst=subst_run(se, begin, msg, &nmatches))==0)
		goto error; /* not found */
	for (rpl=lst; rpl; rpl=rpl->next){
		LM_DBG("%s: replacing at offset %d [%.*s] with [%.*s]\n",
				exports.name, rpl->offset+off,
				rpl->size, rpl->offset+off+msg->buf,
				rpl->rpl.len, rpl->rpl.s);
		if ((l=del_lump(msg, rpl->offset+off, rpl->size, 0))==0)
			goto error;
		/* hack to avoid re-copying rpl, possible because both 
		 * replace_lst & lumps use pkg_malloc */
		if (insert_new_lump_after(l, rpl->rpl.s, rpl->rpl.len, 0)==0){
			LM_ERR("ERROR: %s: subst_f: could not insert new lump\n",
					exports.name);
			goto error;
		}
		/* hack continued: set rpl.s to 0 so that replace_lst_free will
		 * not free it */
		rpl->rpl.s=0;
		rpl->rpl.len=0;
	}
	ret=1;
error:
	LM_DBG("lst was %p\n", lst);
	if (lst) replace_lst_free(lst);
	if (nmatches<0)
		LM_ERR("ERROR: %s: subst_run failed\n", exports.name);
	return ret;
}



/* sed-perl style re: s/regular expression/replacement/flags, like
 *  subst but works on the message uri */
static int subst_uri_f(struct sip_msg* msg, char*  subst, char* ignored)
{
	char* tmp;
	int len;
	char c;
	struct subst_expr* se;
	str* result;
	
	se=(struct subst_expr*)subst;
	if (msg->new_uri.s){
		len=msg->new_uri.len;
		tmp=msg->new_uri.s;
	}else{
		tmp=msg->first_line.u.request.uri.s;
		len	=msg->first_line.u.request.uri.len;
	};
	/* ugly hack: 0 s[len], and restore it afterward
	 * (our re functions require 0 term strings), we can do this
	 * because we always alloc len+1 (new_uri) and for first_line, the
	 * message will always be > uri.len */
	c=tmp[len];
	tmp[len]=0;
	result=subst_str(tmp, msg, se, 0); /* pkg malloc'ed result */
	tmp[len]=c;
	if (result){
		LM_DBG("%s match - old uri= [%.*s], new uri= [%.*s]\n",
				exports.name, len, tmp,
				(result->len)?result->len:0,(result->s)?result->s:"");
		if (msg->new_uri.s) pkg_free(msg->new_uri.s);
		msg->new_uri=*result;
		msg->parsed_uri_ok=0; /* reset "use cached parsed uri" flag */
		pkg_free(result); /* free str* pointer */
		return 1; /* success */
	}
	return -1; /* false, no subst. made */
}
	


/* sed-perl style re: s/regular expression/replacement/flags, like
 *  subst but works on the user part of the uri */
static int subst_user_f(struct sip_msg* msg, char*  subst, char* ignored)
{
	int rval;
	str* result;
	struct subst_expr* se;
	struct action act;
	str user;
	char c;
	int nmatches;

	c=0;
	if (parse_sip_msg_uri(msg)<0){
		return -1; /* error, bad uri */
	}
	if (msg->parsed_uri.user.s==0){
		/* no user in uri */
		user.s="";
		user.len=0;
	}else{
		user=msg->parsed_uri.user;
		c=user.s[user.len];
		user.s[user.len]=0;
	}
	se=(struct subst_expr*)subst;
	result=subst_str(user.s, msg, se, &nmatches);/* pkg malloc'ed result */
	if (c)	user.s[user.len]=c;
	if (result == NULL) {
		if (nmatches<0)
			LM_ERR("subst_user(): subst_str() failed\n");
		return -1;
	}
	/* result->s[result->len] = '\0';  --subst_str returns 0-term strings */
	memset(&act, 0, sizeof(act)); /* be on the safe side */
	act.type = SET_USER_T;
	act.elem[0].type = STR_ST;
	act.elem[0].u.s = *result;
	rval = do_action(&act, msg);
	pkg_free(result->s);
	pkg_free(result);
	return rval;
}


/* sed-perl style re: s/regular expression/replacement/flags */
static int subst_body_f(struct sip_msg* msg, char*  subst, char* ignored)
{
	struct lump* l;
	struct replace_lst* lst;
	struct replace_lst* rpl;
	char* begin;
	struct subst_expr* se;
	int off;
	int ret;
	int nmatches;
	str body;

	body.s = get_body(msg);
	if (body.s==0) {
		LM_ERR("failed to get the message body\n");
		return -1;
	}
	body.len = msg->len -(int)(body.s-msg->buf);
	if (body.len==0) {
		LM_DBG("message body has zero length\n");
		return -1;
	}
	
	se=(struct subst_expr*)subst;
	begin=body.s;
	
	off=begin-msg->buf;
	ret=-1;
	if ((lst=subst_run(se, begin, msg, &nmatches))==0)
		goto error; /* not found */
	for (rpl=lst; rpl; rpl=rpl->next){
		LM_DBG("%s replacing at offset %d [%.*s] with [%.*s]\n",
				exports.name, rpl->offset+off,
				rpl->size, rpl->offset+off+msg->buf,
				rpl->rpl.len, rpl->rpl.s);
		if ((l=del_lump(msg, rpl->offset+off, rpl->size, 0))==0)
			goto error;
		/* hack to avoid re-copying rpl, possible because both 
		 * replace_lst & lumps use pkg_malloc */
		if (insert_new_lump_after(l, rpl->rpl.s, rpl->rpl.len, 0)==0){
			LM_ERR("%s could not insert new lump\n",
					exports.name);
			goto error;
		}
		/* hack continued: set rpl.s to 0 so that replace_lst_free will
		 * not free it */
		rpl->rpl.s=0;
		rpl->rpl.len=0;
	}
	ret=1;
error:
	LM_DBG("lst was %p\n", lst);
	if (lst) replace_lst_free(lst);
	if (nmatches<0)
		LM_ERR("%s subst_run failed\n", exports.name);
	return ret;
}


static inline int find_line_start(char *text, unsigned int text_len,
				  char **buf, unsigned int *buf_len)
{
    char *ch, *start;
    unsigned int len;

    start = *buf;
    len = *buf_len;

    while (text_len <= len) {
	if (strncmp(text, start, text_len) == 0) {
	    *buf = start;
	    *buf_len = len;
	    return 1;
	}
	if ((ch = memchr(start, 13, len - 1))) {
	    if (*(ch + 1) != 10) {
		LM_ERR("No LF after CR\n");
		return 0;
	    }
	    len = len - (ch - start + 2);
	    start = ch + 2;
	} else {
	    LM_ERR("No CRLF found\n");
	    return 0;
	}
    }
    return 0;
}


/* Filters multipart body by leaving out everything else except
 * first body part of given content type. */
static int filter_body_f(struct sip_msg* msg, char* _content_type,
			 char* ignored)
{
	char *start;
	unsigned int len;
	str *content_type, body;

	body.s = get_body(msg);
	if (body.s == 0) {
		LM_ERR("Failed to get the message body\n");
		return -1;
	}
	body.len = msg->len - (int)(body.s - msg->buf);
	if (body.len == 0) {
		LM_DBG("Message body has zero length\n");
		return -1;
	}
	
	content_type = (str *)_content_type;
	start = body.s;
	len = body.len;
	
	while (find_line_start("Content-Type: ", 14, &start, &len)) {
	    start = start + 14;
	    len = len - 14;
	    if (len > content_type->len + 2) {
		if (strncasecmp(start, content_type->s, content_type->len)
		    == 0) {
		    start = start + content_type->len;
		    len = len - content_type->len;
		    if ((*start != 13) || (*(start + 1) != 10)) {
			LM_ERR("No CRLF found after content type\n");
			return -1;
		    }
		    while ((len > 3) && !(*start == 13 && *(start+1) == 10 && *(start+2) == 13 && *(start+3) == 10)) {
			len = len - 1;
			start = start + 1;
		    }
		    while ((len > 0) && ((*start == 13) || (*start == 10))) {
			len = len - 1;
			start = start + 1;
		    }
		    if (del_lump(msg, body.s - msg->buf, start - body.s, 0)
			== 0) {
			LM_ERR("Deleting lump <%.*s> failed\n",
			       (int)(start - body.s), body.s);
			return -1;
		    }
		    if (find_line_start("--Boundary", 10, &start, &len)) {
			if (del_lump(msg, start - msg->buf, len, 0) == 0) {
			    LM_ERR("Deleting lump <%.*s> failed\n",
				   len, start);
			    return -1;
			} else {
			    return 1;
			}
		    } else {
			LM_ERR("Boundary not found after content\n");
			return -1;
		    }
		}
	    } else {
		return -1;
	    }
	}
	return -1;
}


static int remove_hf_f(struct sip_msg* msg, char* str_hf, char* foo)
{
	struct hdr_field *hf;
	struct lump* l;
	int cnt;
	gparam_p gp;

	gp = (gparam_p)str_hf;
	cnt=0;

	/* we need to be sure we have seen all HFs */
	parse_headers(msg, HDR_EOH_F, 0);
	for (hf=msg->headers; hf; hf=hf->next) {
		/* for well known header names str_hf->s will be set to NULL 
		   during parsing of opensips.cfg and str_hf->len contains 
		   the header type */
		if(gp->type==GPARAM_TYPE_INT)
		{
			if (gp->v.ival!=hf->type)
				continue;
		} else {
			if (hf->type!=HDR_OTHER_T)
				continue;
			if (hf->name.len!=gp->v.sval.len)
				continue;
			if (strncasecmp(hf->name.s, gp->v.sval.s, hf->name.len)!=0)
				continue;
		}
		l=del_lump(msg, hf->name.s-msg->buf, hf->len, 0);
		if (l==0) {
			LM_ERR("no memory\n");
			return -1;
		}
		cnt++;
	}
	return cnt==0 ? -1 : 1;
}

static int is_present_hf_f(struct sip_msg* msg, char* str_hf, char* foo)
{
	struct hdr_field *hf;
	gparam_p gp;

	gp = (gparam_p)str_hf;

	/* we need to be sure we have seen all HFs */
	parse_headers(msg, HDR_EOH_F, 0);
	for (hf=msg->headers; hf; hf=hf->next) {
		if(gp->type==GPARAM_TYPE_INT)
		{
			if (gp->v.ival!=hf->type)
				continue;
		} else {
			if (hf->type!=HDR_OTHER_T)
				continue;
			if (hf->name.len!=gp->v.sval.len)
				continue;
			if (strncasecmp(hf->name.s,gp->v.sval.s,hf->name.len)!=0)
				continue;
		}
		return 1;
	}
	return -1;
}


static int fixup_substre(void** param, int param_no)
{
	struct subst_expr* se;
	str subst;

	LM_DBG("%s module -- fixing %s\n", exports.name, (char*)(*param));
	if (param_no!=1) return 0;
	subst.s=*param;
	subst.len=strlen(*param);
	se=subst_parser(&subst);
	if (se==0){
		LM_ERR("%s: bad subst. re %s\n", exports.name, 
				(char*)*param);
		return E_BAD_RE;
	}
	/* don't free string -- needed for specifiers */
	/* pkg_free(*param); */
	/* replace it with the compiled subst. re */
	*param=se;
	return 0;
}


static int append_time_f(struct sip_msg* msg, char* p1, char *p2)
{


	size_t len;
	char time_str[MAX_TIME];
	time_t now;
	struct tm *bd_time;

	now=time(0);

	bd_time=gmtime(&now);
	if (bd_time==NULL) {
		LM_ERR("gmtime failed\n");
		return -1;
	}

	len=strftime(time_str, MAX_TIME, TIME_FORMAT, bd_time);
	if (len>MAX_TIME-2 || len==0) {
		LM_ERR("unexpected time length\n");
		return -1;
	}

	time_str[len]='\r';
	time_str[len+1]='\n';


	if (add_lump_rpl(msg, time_str, len+2, LUMP_RPL_HDR)==0)
	{
		LM_ERR("unable to add lump\n");
		return -1;
	}

	return 1;
}


static int append_to_reply_f(struct sip_msg* msg, char* key, char* str0)
{
	str s0;

	if(key==NULL)
	{
		LM_ERR("bad parameters\n");
		return -1;
	}

	if(fixup_get_svalue(msg, (gparam_p)key, &s0)!=0)
	{
		LM_ERR("cannot print the format\n");
		return -1;
	}
 
	if ( add_lump_rpl( msg, s0.s, s0.len, LUMP_RPL_HDR)==0 )
	{
		LM_ERR("unable to add lump_rl\n");
		return -1;
	}

	return 1;
}


/* add str1 to end of header or str1.r-uri.str2 */

static int add_hf_helper(struct sip_msg* msg, str *str1, str *str2,
		gparam_p hfval, int mode, gparam_p hfanc)
{
	struct lump* anchor;
	struct hdr_field *hf;
	char *s;
	int len;
	str s0;

	if (parse_headers(msg, HDR_EOH_F, 0) == -1) {
		LM_ERR("error while parsing message\n");
		return -1;
	}
	
	hf = 0;
	if(hfanc!=NULL) {
		for (hf=msg->headers; hf; hf=hf->next) {
			if(hfanc->type==GPARAM_TYPE_INT)
			{
				if (hfanc->v.ival!=hf->type)
					continue;
			} else {
				if (hf->type!=HDR_OTHER_T)
					continue;
				if (hf->name.len!=hfanc->v.sval.len)
					continue;
				if (strncasecmp(hf->name.s,hfanc->v.sval.s,hf->name.len)!=0)
					continue;
			}
			break;
		}
	}

	if(mode == 0) { /* append */
		if(hf==0) { /* after last header */
			anchor = anchor_lump(msg, msg->unparsed - msg->buf, 0, 0);
		} else { /* after hf */
			anchor = anchor_lump(msg, hf->name.s + hf->len - msg->buf, 0, 0);
		}
	} else { /* insert */
		if(hf==0) { /* before first header */
			anchor = anchor_lump(msg, msg->headers->name.s - msg->buf, 0, 0);
		} else { /* before hf */
			anchor = anchor_lump(msg, hf->name.s - msg->buf, 0, 0);
		}
	}

	if(anchor == 0) {
		LM_ERR("can't get anchor\n");
		return -1;
	}

	if(str1) {
		s0 = *str1;
	} else {
		if(hfval) {
			if(fixup_get_svalue(msg, hfval, &s0)!=0)
			{
				LM_ERR("cannot print the format\n");
				return -1;
			}
		} else {
			s0.len = 0;
			s0.s   = 0;
		}
	}
		
	len=s0.len;
	if (str2) len+= str2->len + REQ_LINE(msg).uri.len;

	s = (char*)pkg_malloc(len);
	if (!s) {
		LM_ERR("no pkg memory left\n");
		return -1;
	}

	memcpy(s, s0.s, s0.len);
	if (str2) {
		memcpy(s+str1->len, REQ_LINE(msg).uri.s, REQ_LINE(msg).uri.len);
		memcpy(s+str1->len+REQ_LINE(msg).uri.len, str2->s, str2->len );
	}

	if (insert_new_lump_before(anchor, s, len, 0) == 0) {
		LM_ERR("can't insert lump\n");
		pkg_free(s);
		return -1;
	}
	return 1;
}

static int append_hf_1(struct sip_msg *msg, char *str1, char *str2 )
{
	return add_hf_helper(msg, 0, 0, (gparam_p)str1, 0, 0);
}

static int append_hf_2(struct sip_msg *msg, char *str1, char *str2 )
{
	return add_hf_helper(msg, 0, 0, (gparam_p)str1, 0,
			(gparam_p)str2);
}

static int insert_hf_1(struct sip_msg *msg, char *str1, char *str2 )
{
	return add_hf_helper(msg, 0, 0, (gparam_p)str1, 1, 0);
}

static int insert_hf_2(struct sip_msg *msg, char *str1, char *str2 )
{
	return add_hf_helper(msg, 0, 0, (gparam_p)str1, 1, 
			(gparam_p)str2);
}

static int append_urihf(struct sip_msg *msg, char *str1, char *str2)
{
	return add_hf_helper(msg, (str*)str1, (str*)str2, 0, 0, 0);
}

static int is_method_f(struct sip_msg *msg, char *meth, char *str2 )
{
	str *m;

	m = (str*)meth;
	if(msg->first_line.type==SIP_REQUEST)
	{
		if(m->s==0)
			return (msg->first_line.u.request.method_value&m->len)?1:-1;
		else
			return (msg->first_line.u.request.method_value==METHOD_OTHER
					&& msg->first_line.u.request.method.len==m->len
					&& (strncasecmp(msg->first_line.u.request.method.s, m->s,
					m->len)==0))?1:-1;
	}
	if(parse_headers(msg, HDR_CSEQ_F, 0)!=0 || msg->cseq==NULL)
	{
		LM_ERR("cannot parse cseq header\n");
		return -1; /* should it be 0 ?!?! */
	}
	if(m->s==0)
		return (get_cseq(msg)->method_id&m->len)?1:-1;
	else
		return (get_cseq(msg)->method_id==METHOD_OTHER
				&& get_cseq(msg)->method.len==m->len
				&& (strncasecmp(get_cseq(msg)->method.s, m->s,
				m->len)==0))?1:-1;
}


/*
 * Convert char* header_name to str* parameter
 */
static int hname_fixup(void** param, int param_no)
{
	char c;
	struct hdr_field hdr;
	gparam_p gp = NULL;
	
	gp = (gparam_p)pkg_malloc(sizeof(gparam_t));
	if(gp == NULL)
	{
		LM_ERR("no more memory\n");
		return E_UNSPEC;
	}
	memset(gp, 0, sizeof(gparam_t));

	gp->v.sval.s = (char*)*param;
	gp->v.sval.len = strlen(gp->v.sval.s);
	if(gp->v.sval.len==0)
	{
		LM_ERR("empty header name parameter\n");
		pkg_free(gp);
		return E_UNSPEC;
	}
	
	c = gp->v.sval.s[gp->v.sval.len];
	gp->v.sval.s[gp->v.sval.len] = ':';
	gp->v.sval.len++;
	
	if (parse_hname2(gp->v.sval.s, gp->v.sval.s
				+ ((gp->v.sval.len<4)?4:gp->v.sval.len), &hdr)==0)
	{
		LM_ERR("error parsing header name\n");
		pkg_free(gp);
		return E_UNSPEC;
	}
	
	gp->v.sval.len--;
	gp->v.sval.s[gp->v.sval.len] = c;

	if (hdr.type!=HDR_OTHER_T && hdr.type!=HDR_ERROR_T)
	{
		LM_INFO("using hdr type (%d) instead of <%.*s>\n",
				hdr.type, gp->v.sval.len, gp->v.sval.s);
		pkg_free(gp->v.sval.s);
		gp->v.sval.s = NULL;
		gp->v.ival = hdr.type;
		gp->type = GPARAM_TYPE_INT;
	} else {
		gp->type = GPARAM_TYPE_STR;
		LM_INFO("using hdr type name <%.*s>\n", gp->v.sval.len, gp->v.sval.s);
	}
	
	*param = (void*)gp;
	return 0;
}

static int free_hname_fixup(void** param, int param_no)
{
	if(*param)
	{
		if(((gparam_p)(*param))->type==GPARAM_TYPE_STR)
			pkg_free(((gparam_p)(*param))->v.sval.s);
		pkg_free(*param);
		*param = 0;
	}
	return 0;
}

/*
 * Convert char* method to str* parameter
 */
static int fixup_method(void** param, int param_no)
{
	str* s;
	char *p;
	int m;
	unsigned int method;
	
	s = (str*)pkg_malloc(sizeof(str));
	if (!s) {
		LM_ERR("no pkg memory left\n");
		return E_UNSPEC;
	}

	s->s = (char*)*param;
	s->len = strlen(s->s);
	if(s->len==0)
	{
		LM_ERR("empty method name\n");
		pkg_free(s);
		return E_UNSPEC;
	}
	m=0;
	p=s->s;
	while(*p)
	{
		if(*p=='|')
		{
			*p = ',';
			m=1;
		}
		p++;
	}
	if(parse_methods(s, &method)!=0)
	{
		LM_ERR("bad method names\n");
		pkg_free(s);
		return E_UNSPEC;
	}

	if(m==1)
	{
		if(method==METHOD_UNDEF || method&METHOD_OTHER)
		{
			LM_ERR("unknown method in list [%.*s/%d] - must be only defined methods\n",
				s->len, s->s, method);
			return E_UNSPEC;
		}
		LM_DBG("using id for methods [%.*s/%d]\n",
				s->len, s->s, method);
		s->s = 0;
		s->len = method;
	} else {
		if(method!=METHOD_UNDEF && method!=METHOD_OTHER)
		{
			LM_DBG("using id for method [%.*s/%d]\n",
				s->len, s->s, method);
			s->s = 0;
			s->len = method;
		} else
			LM_DBG("name for method [%.*s/%d]\n",
				s->len, s->s, method);
	}

	*param = (void*)s;
	return 0;
}

/*
 * Convert char* privacy value to corresponding bit value
 */
static int fixup_privacy(void** param, int param_no)
{
    str p;
    unsigned int val;

    p.s = (char*)*param;
    p.len = strlen(p.s);

    if (p.len == 0) {
	LM_ERR("empty privacy value\n");
	return E_UNSPEC;
    }

    if (parse_priv_value(p.s, p.len, &val) != p.len) {
	LM_ERR("invalid privacy value\n");
	return E_UNSPEC;
    }
    
    *param = (void *)(long)val;
    return 0;
}

static int add_header_fixup(void** param, int param_no)
{
	if(param_no==1)
	{
		return fixup_spve_null(param, param_no);
	} else if(param_no==2) {
		return hname_fixup(param, param_no);
	} else {
		LM_ERR("wrong number of parameters\n");
		return E_UNSPEC;
	}
}


static int fixup_body_type(void** param, int param_no)
{
	char *p;
	char *r;
	unsigned int type;

	if(param_no==1) {
		p = (char*)*param;
		if (p==0 || p[0]==0) {
			type = 0;
		} else {
			r = decode_mime_type( p, p+strlen(p) , &type , NULL);
			if (r==0) {
				LM_ERR("unsupported mime <%s>\n",p);
				return E_CFG;
			}
			if ( r!=p+strlen(p) ) {
				LM_ERR("multiple mimes not supported!\n");
				return E_CFG;
			}
		}
		pkg_free(*param);
		*param = (void*)(long)type;
	}
	return 0;

}


static int has_body_f(struct sip_msg *msg, char *type, char *str2 )
{
	struct multi_body * m;
	struct part * p;

	/* parse content len hdr */
	if ( msg->content_length==NULL &&
	(parse_headers(msg,HDR_CONTENTLENGTH_F, 0)==-1||msg->content_length==NULL))
		return -1;

	if (get_content_length (msg)==0) {
		LM_DBG("content length is zero\n");
		/* Nothing to see here, please move on. */
		return -1;
	}

	if( ( ((int)(long)type )>>16) == TYPE_MULTIPART )
	{
		int mime = parse_content_type_hdr(msg);

		if( mime == ((int)(long)type ) )
			return 1;

		return -1;
	}

	/* check type also? */
	if (type==0)
		return 1;

	m = get_all_bodies(msg);

	if (m == NULL)
	{
		LM_ERR("Failed to get bodies\n");
		return -1;
	}

	/* if there is no multipart and the type is unspecified default to
	   application/sdp */

	if (m->from_multi_part == 0 && m->part_count == 1 && m->first->content_type == 0)
	{
		m->first->content_type = ((TYPE_APPLICATION << 16) + SUBTYPE_SDP);
	}

	p = m->first;
	while (p)
	{
		if( p->content_type == ((int)(long)type ) )
			return 1;
		p = p->next;
	}
	
	return -1;
}


static int is_privacy_f(struct sip_msg *msg, char *_privacy, char *str2 )
{
    if (parse_privacy(msg) == -1)
	return -1;

    return get_privacy_values(msg) & ((unsigned int)(long)_privacy) ? 1 : -1;

}


/*
 *	Function to remove the body of a message
 * */
static int strip_body_f(struct sip_msg *msg, char *str1, char *str2 )
{
	int body_len;
	char* body;

	/* get body pointer */
	body= get_body(msg);
	if (body ==0 )
		return -1;

	/* all headears are already parsed by "get_body" */
	if (msg->content_length==0) {
		LM_ERR("very bogus message with body, but no content length hdr\n");
		return -1;
	}

	body_len= get_content_length (msg);
	if (body_len==0) {
		LM_DBG("content length is zero\n");
		return -1;
	}
	
	/* delete all body lumps from the list */
	free_lump_list(msg->body_lumps);
	msg->body_lumps = NULL;

	/* add delete body lump */
	if( del_lump(msg, body- msg->buf, body_len, HDR_EOH_T) == 0) {
		LM_ERR("failed to add lump to delete body\n");
		return -1;
	}

	/* add delete content-type header lump */
	if(del_lump(msg, msg->content_type->name.s- msg->buf, msg->content_type->len,
				HDR_CONTENTTYPE_T) == 0) {
		LM_ERR("failed to add lump to delete content type header\n");
		return -1;
	}

	return 1;
}

static int strip_body_f2(struct sip_msg *msg, char *type, char *str2 )
{
	struct multi_body * m;
	struct part * p;
	int deleted = 0,mime;
	

	/* parse content len hdr */
	if ( msg->content_length==NULL &&
	(parse_headers(msg,HDR_CONTENTLENGTH_F, 0)==-1||msg->content_length==NULL))
		return -1;

	if (get_content_length (msg)==0) {
		LM_DBG("content length is zero\n");
		/* Nothing to see here, please move on. */
		return -1;
	}

	mime = parse_content_type_hdr(msg);

	if( ( ((int)(long)type )>>16) == TYPE_MULTIPART || (mime >>16) != TYPE_MULTIPART)
	{
		

		if( mime == ((int)(long)type ) )
		{
			strip_body_f(msg,NULL,NULL);
		}

		return -1;
	}
	

	m = get_all_bodies(msg);

	if (m == NULL)
	{
		LM_ERR("Failed to get bodies\n");
		return -1;
	}

	/* if there is no multipart and the type is unspecified default to
	   application/sdp */

	if (m->from_multi_part == 0 && m->part_count == 1 && m->first->content_type == 0)
	{
		m->first->content_type = ((TYPE_APPLICATION << 16) + SUBTYPE_SDP);
	}

	p = m->first;

	deleted = -1;
	while (p)
	{
		if( p->content_type == ((int)(long)type ) )
		{
			if( del_lump( msg, p->all_data.s - msg->buf - 4 - m->boundary.len,
				 p->all_data.len + 6 + m->boundary.len, 0 ) == 0 )
			{
				LM_ERR("Failed to add body lump\n");
				return -1;
			}
			
			deleted =  1;
		}
			
		p = p->next;
	}

	return deleted;
}

/*
 *	Function to add a new body
 * */
static int add_body_f(struct sip_msg *msg, gparam_p nbody, gparam_p ctype )
{
	int body_len;
	char* body;
	struct lump* anchor;
	unsigned int offset;
	str new_body;
	char* value= NULL;
	str content_type, ctype_hf;


	if(fixup_get_svalue(msg, nbody, &new_body)!=0) {
		LM_ERR("cannot print the format\n");
		return -1;
	}

	if(new_body.s== NULL || new_body.len == 0) {
		LM_ERR("null body parameter\n");
		return -1;
	}

	/* must delete all body lumps from the list */
	free_lump_list(msg->body_lumps);
	msg->body_lumps = NULL;

	/* get body pointer */
	body= get_body(msg);
	if(body== NULL ) {
		LM_ERR("parsing failed\n");
		return -1;
	}
	
	offset = body - msg->buf;
	body_len= get_content_length (msg);
	if (body_len!=0) {
		/* delete old body */
		if(del_lump(msg, offset, body_len, HDR_EOH_T) == 0) {
			LM_ERR("failed to add lump to delete body");
			return -1;
		}
	}
	else
	{
		LM_DBG("content length is zero\n");
		if(ctype== NULL)
		{
			LM_ERR("No body found and no content-type name given"
					" as parameter\n");
			return -1;
		}
	}

	/* add an add body lump */
	anchor = anchor_lump(msg, offset, 0, 0);
	if(anchor == 0) {
		LM_ERR("failed to insert an add new body anchor");
		return -1;
	}

	value = (char*)pkg_malloc(new_body.len);
	if(value== NULL) {
		LM_ERR("no more memory\n");
		return -1;
	}
	memcpy(value, new_body.s, new_body.len);

	if (insert_new_lump_before(anchor, value, new_body.len, 0) == 0) {
		LM_ERR("failed to insert lump\n");
		pkg_free(value);
		return -1;
	}
	
	if(ctype) {
		if(fixup_get_svalue(msg, ctype, &content_type)!=0) {
			LM_ERR("cannot print the format\n");
			return -1;
		}
		
		if(msg->content_type) {
			/* verify if the parameter has the same value */
			if(content_type.len == msg->content_type->body.len &&
					strncmp(msg->content_type->body.s, content_type.s, content_type.len)== 0)
			{
				return 1;
			}

			if(del_lump(msg, msg->content_type->name.s- msg->buf, msg->content_type->len,
				HDR_CONTENTTYPE_T) == 0) {
				LM_ERR("failed to add lump to delete content type header\n");
				return -1;
			}
		}
		/* add new Content-Type header */
		
		/* construct header */
		
		ctype_hf.len = strlen("Content-Type: ") + content_type.len+ CRLF_LEN;
		ctype_hf.s = (char*)pkg_malloc(ctype_hf.len);
		if(ctype_hf.s == NULL) {
			LM_ERR("no more memory\n");
			return -1;
		}
		sprintf(ctype_hf.s, "Content-Type: %.*s%s", content_type.len,
				content_type.s, CRLF);
		
		if( add_hf_helper(msg, &ctype_hf, 0, 0, 0, 0)< 0) {
			LM_ERR("failed to add content type header\n");
			pkg_free(ctype_hf.s);
			return -1;
		}
		pkg_free(ctype_hf.s);
	}


	return 1;
}


static int add_body_f_1(struct sip_msg *msg, char *nbody, char *ctype )
{
	return add_body_f(msg, (gparam_p)nbody, NULL);
}

static int add_body_f_2(struct sip_msg *msg, char *nbody, char *ctype )
{
	return add_body_f(msg, (gparam_p)nbody, (gparam_p)ctype);
}

static int is_audio_on_hold_f(struct sip_msg *msg, char *str1, char *str2 )
{
	int sdp_session_num = 0, sdp_stream_num;
	sdp_session_cell_t* sdp_session;
	sdp_stream_cell_t* sdp_stream;

	if (0 == parse_sdp(msg)) {
		for(;;) {
			sdp_session = get_sdp_session(msg, sdp_session_num);
			if(!sdp_session) break;
			sdp_stream_num = 0;
			for(;;) {
				sdp_stream = get_sdp_stream(msg, sdp_session_num, sdp_stream_num);
				if(!sdp_stream) break;
				if(sdp_stream->media.len==AUDIO_STR_LEN &&
					strncmp(sdp_stream->media.s,AUDIO_STR,AUDIO_STR_LEN)==0 &&
					sdp_stream->is_on_hold)
					return 1;
				sdp_stream_num++;
			}
			sdp_session_num++;
		}
	}
	return -1;
}
