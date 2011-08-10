/*
 * $Id: dlg_handlers.c 6238 2009-10-09 10:51:29Z bogdan_iancu $
 *
 * Copyright (C) 2006-2009 Voice System SRL
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
 * 2006-04-14  initial version (bogdan)
 * 2006-11-28  Added support for tracking the number of early dialogs, and the
 *             number of failed dialogs. This involved updates to dlg_onreply()
 *             (Jeffrey Magder - SOMA Networks)
 * 2007-03-06  syncronized state machine added for dialog state. New tranzition
 *             design based on events; removed num_1xx and num_2xx (bogdan)
 * 2007-04-30  added dialog matching without DID (dialog ID), but based only
 *             on RFC3261 elements - based on an original patch submitted 
 *             by Michel Bensoussan <michel@extricom.com> (bogdan)
 * 2007-05-17  new feature: saving dialog info into a database if 
 *             realtime update is set(ancuta)
 * 2007-07-06  support for saving additional dialog info : cseq, contact, 
 *             route_set and socket_info for both caller and callee (ancuta)
 * 2007-07-10  Optimized dlg_match_mode 2 (DID_NONE), it now employs a proper
 *             hash table lookup and isn't dependant on the is_direction 
 *             function (which requires an RR param like dlg_match_mode 0 
 *             anyways.. ;) ; based on a patch from 
 *             Tavis Paquette <tavis@galaxytelecom.net> 
 *             and Peter Baer <pbaer@galaxytelecom.net>  (bogdan)
 * 2008-04-04  added direction reporting in dlg callbacks (bogdan)
 * 2009-09-09  support for early dialogs added; proper handling of cseq
 *             while PRACK is used (bogdan)
 */


#include <string.h>
#include <time.h>

#include "../../trim.h"
#include "../../pvar.h"
#include "../../timer.h"
#include "../../statistics.h"
#include "../../parser/parse_from.h"
#include "../../parser/parse_cseq.h"
#include "../../parser/contact/parse_contact.h"
#include "../../parser/parse_from.h"
#include "../../parser/parse_rr.h"
#include "../tm/tm_load.h"
#include "../rr/api.h"
#include "dlg_hash.h"
#include "dlg_timer.h"
#include "dlg_cb.h"
#include "dlg_handlers.h"
#include "dlg_db_handler.h"
#include "dlg_profile.h"
#include "dlg_req_within.h"

static str       rr_param;
static int       dlg_flag;
static pv_spec_t *timeout_avp;
static int       default_timeout;
static int       seq_match_mode;
static int       shutdown_done = 0;

extern struct rr_binds d_rrb;
extern int bye_on_timeout_flag;

/* statistic variables */
extern stat_var *early_dlgs;
extern stat_var *processed_dlgs;
extern stat_var *expired_dlgs;
extern stat_var *failed_dlgs;

int  last_dst_leg = -1;

#define RR_DLG_PARAM_SIZE  (2*2*sizeof(int)+3+MAX_DLG_RR_PARAM_NAME)
#define DLG_SEPARATOR      '.'



void init_dlg_handlers(char *rr_param_p, int dlg_flag_idx,
		pv_spec_t *timeout_avp_p ,int default_timeout_p, 
		int seq_match_mode_p)
{
	rr_param.s = rr_param_p;
	rr_param.len = strlen(rr_param.s);

	dlg_flag = (dlg_flag_idx==-1) ? 0 : (1<<dlg_flag_idx) ;

	timeout_avp = timeout_avp_p;
	default_timeout = default_timeout_p;
	seq_match_mode = seq_match_mode_p;
}


void destroy_dlg_handlers(void)
{
	shutdown_done = 1;
}


static inline int add_dlg_rr_param(struct sip_msg *req, unsigned int entry,
													unsigned int id)
{
	static char buf[RR_DLG_PARAM_SIZE];
	str s;
	int n;
	char *p;

	s.s = p = buf;

	*(p++) = ';';
	memcpy(p, rr_param.s, rr_param.len);
	p += rr_param.len;
	*(p++) = '=';

	n = RR_DLG_PARAM_SIZE - (p-buf);
	if (int2reverse_hex( &p, &n, entry)==-1)
		return -1;

	*(p++) = DLG_SEPARATOR;

	n = RR_DLG_PARAM_SIZE - (p-buf);
	if (int2reverse_hex( &p, &n, id)==-1)
		return -1;

	s.len = p-buf;

	if (d_rrb.add_rr_param( req, &s)<0) {
		LM_ERR("failed to add rr param\n");
		return -1;
	}

	return 0;
}



static inline void get_routing_info(struct sip_msg *msg, int is_req,
							unsigned int *skip_rrs, str *contact, str *rr_set)
{
	/* extract the contact address */
	if (!msg->contact&&(parse_headers(msg,HDR_CONTACT_F,0)<0||!msg->contact)){
		//LM_ERR("bad sip message or missing Contact hdr\n");
		contact->s = NULL;
		contact->len = 0;
	} else {
		if ( parse_contact(msg->contact)<0 ||
		((contact_body_t *)msg->contact->parsed)->contacts==NULL ||
		((contact_body_t *)msg->contact->parsed)->contacts->next!=NULL ) {
			LM_ERR("bad Contact HDR\n");
			contact->s = NULL;
			contact->len = 0;
		} else {
			*contact = ((contact_body_t *)msg->contact->parsed)->contacts->uri;
		}
	}

	/* extract the RR parts - parse all headers as we can have multiple 
	   RR headers in the same message */
	if( parse_headers(msg,HDR_EOH_F,0)<0 ){
		LM_ERR("failed to parse record route header\n");
		rr_set->s = 0;
		rr_set->len = 0;
	} else {
		if(msg->record_route){
			if( print_rr_body(msg->record_route, rr_set, !is_req,
								skip_rrs) != 0 ){
				LM_ERR("failed to print route records \n");
				rr_set->s = 0;
				rr_set->len = 0;
			}
		} else {
			rr_set->s = 0;
			rr_set->len = 0;
		}
	}
}



/*usage: dlg: the dialog to add cseq, contact & record_route
 * 		 msg: sip message
 * 		 flag: 0-for a request(INVITE), 
 * 		 		1- for a reply(200 ok)
 *
 *	for a request: get record route in normal order
 *	for a reply  : get in reverse order, skipping the ones from the request and
 *				   the proxies' own 
 */
static int init_leg_info( struct dlg_cell *dlg, struct sip_msg *msg,
													struct cell* t, str *tag)
{
	unsigned int skip_recs;
	str cseq;
	str contact;
	str rr_set;
	int is_req;

	is_req = (msg->first_line.type==SIP_REQUEST)?1:0;

	/* extract the cseq number as string */
	if (is_req) {
		/* cseq */
		if((!msg->cseq && (parse_headers(msg,HDR_CSEQ_F,0)<0 || !msg->cseq)) ||
		!msg->cseq->parsed){
			LM_ERR("bad sip message or missing CSeq hdr :-/\n");
			goto error0;
		}
		cseq = (get_cseq(msg))->number;

		/* routing info */
		skip_recs = 0;
		get_routing_info(msg, is_req, &skip_recs, &contact, &rr_set);
		dlg->from_rr_nb = skip_recs;
	} else {
		/* use the same as in caller part */
		cseq = dlg->legs[DLG_CALLER_LEG].r_cseq;
		rr_set.len = contact.len = 0;
		rr_set.s = contact.s = NULL;
	}

	LM_DBG("route_set %.*s, contact %.*s, cseq %.*s and bind_addr %.*s\n",
		rr_set.len, ZSW(rr_set.s), contact.len, ZSW(contact.s),
		cseq.len, cseq.s, 
		msg->rcv.bind_address->sock_str.len,
		msg->rcv.bind_address->sock_str.s);

	if (dlg_add_leg_info( dlg, tag, &rr_set, &contact, &cseq,
	msg->rcv.bind_address)!=0) {
		LM_ERR("dlg_add_leg_info failed\n");
		if (rr_set.s) pkg_free(rr_set.s);
		goto error0;
	}

	if (rr_set.s) pkg_free(rr_set.s);

	return 0;
error0:
	return -1;
}


static inline void push_reply_in_dialog(struct sip_msg *rpl, struct cell* t,
														struct dlg_cell *dlg)
{
	str tag,contact,rr_set;
	unsigned int leg, skip_rrs;

	/* get to tag*/
	if ( !rpl->to && ((parse_headers(rpl,HDR_TO_F,0)<0) || !rpl->to) ){
		LM_ERR("bad reply or missing TO hdr :-/\n");
		tag.s = 0;
		tag.len = 0;
	} else {
		tag = get_to(rpl)->tag_value;
		if (tag.s==0 || tag.len==0) {
			LM_ERR("missing TAG param in TO hdr :-/\n");
			tag.s = 0;
			tag.len = 0;
		}
	}
	LM_DBG("%p totag in rpl is <%.*s> (%d)\n",
		dlg, tag.len,tag.s,tag.len);

	/* ignore provisional replies replies without totag */
	if (tag.len==0 && rpl->REPLY_STATUS<200 )
		return;

	/* is the totag already known ?? */
	for(leg=DLG_FIRST_CALLEE_LEG ; leg<dlg->legs_no[DLG_LEGS_USED] ; leg++ ) {
		if ( dlg->legs[leg].tag.len==tag.len &&
		strncmp(dlg->legs[leg].tag.s,tag.s,tag.len)==0 ) {
			/* we have a match -> branch already known... */
			LM_DBG("branch with tag <%.*s> already exists\n",tag.len,tag.s);
			goto routing_info;
		}
	}

	/* coooool :D ....new totag learned !! -> store it */

	/* save callee's tag and cseq */
	LM_DBG("new branch with tag <%.*s>\n",tag.len,tag.s);
	if (init_leg_info( dlg, rpl, t, &tag) !=0) {
		LM_ERR("could not add further info to the dialog\n");
		return;
	}
	leg = dlg->legs_no[DLG_LEGS_USED] - 1; /* idx of last created leg */

routing_info:
	/* update dlg info only if 2xx reply and if not already done so */
	if (rpl->REPLY_STATUS>=200 && rpl->REPLY_STATUS<300 &&
	dlg->legs_no[DLG_LEG_200OK] != leg) {
		/* set this branch as primary */
		if (!dlg->legs_no[DLG_LEG_200OK])
			dlg->legs_no[DLG_LEG_200OK] = leg;
		/* update routing info */
		skip_rrs = dlg->from_rr_nb +
				((t->relaied_reply_branch>=0)?
					(t->uac[t->relaied_reply_branch].added_rr):0);
		get_routing_info(rpl, 0, &skip_rrs, &contact, &rr_set);
		dlg_update_routing( dlg, leg, &rr_set, &contact );
		if( rr_set.s )
			pkg_free( rr_set.s);
	}
}


static void dlg_onreply(struct cell* t, int type, struct tmcb_params *param)
{
	struct sip_msg *rpl;
	struct dlg_cell *dlg;
	int new_state;
	int old_state;
	int unref;
	int event;

	dlg = (struct dlg_cell *)(*param->param);
	if (shutdown_done || dlg==0)
		return;

	rpl = param->rpl;

	if (type==TMCB_RESPONSE_FWDED) {
		/* this callback is under transaction lock (by TM), so it is save
		   to operate at write level, but we need to take care on write-read
		   conflicts -bogdan */
		if (rpl!=FAKED_REPLY) {
			push_reply_in_dialog( rpl, t, dlg);
		} else {
			LM_DBG("dialog replied from script - cannot get callee info\n");
		}

		/* The state does not change, but the msg is mutable in this callback*/
		run_dlg_callbacks(DLGCB_RESPONSE_FWDED, dlg, rpl, DLG_DIR_UPSTREAM, 0);
		return;
	}
	if (type==TMCB_TRANS_CANCELLED) {
		/* simply attache the dialog to the script
		   and put one more ref */
		/* reference and attached to script */
		ref_dlg(dlg,1);
		current_dlg_pointer = t->dialog_ctx;
		return;
	}

	if (type==TMCB_TRANS_DELETED)
		event = DLG_EVENT_TDEL;
	else if (param->code<200)
		event = DLG_EVENT_RPL1xx;
	else if (param->code<300)
		event = DLG_EVENT_RPL2xx;
	else
		event = DLG_EVENT_RPL3xx;

	next_state_dlg( dlg, event, &old_state, &new_state, &unref);

	if (new_state==DLG_STATE_EARLY) {
		run_dlg_callbacks(DLGCB_EARLY, dlg, rpl, DLG_DIR_UPSTREAM, 0);
		if (old_state!=DLG_STATE_EARLY)
			if_update_stat(dlg_enable_stats, early_dlgs, 1);
		return;
	}

	if (new_state==DLG_STATE_CONFIRMED_NA &&
	old_state!=DLG_STATE_CONFIRMED_NA && old_state!=DLG_STATE_CONFIRMED ) {
		LM_DBG("dialog %p confirmed\n",dlg);

		/* set start time */
		dlg->start_ts = (unsigned int)(time(0));

		/* save the settings to the database, 
		 * if realtime saving mode configured- save dialog now
		 * else: the next time the timer will fire the update*/
		dlg->flags |= DLG_FLAG_NEW;
		if ( dlg_db_mode==DB_MODE_REALTIME )
			update_dialog_dbinfo(dlg);

		if (0 != insert_dlg_timer( &dlg->tl, dlg->lifetime )) {
			LM_CRIT("Unable to insert dlg %p [%u:%u] on event %d [%d->%d] "
				"with clid '%.*s' and tags '%.*s' '%.*s'\n",
				dlg, dlg->h_entry, dlg->h_id, event, old_state, new_state,
				dlg->callid.len, dlg->callid.s,
				dlg->legs[DLG_CALLER_LEG].tag.len,
				dlg->legs[DLG_CALLER_LEG].tag.s,
				dlg->legs[callee_idx(dlg)].tag.len,
				ZSW(dlg->legs[callee_idx(dlg)].tag.s));
		} else {
			/* reference dialog as kept in timer list */
			ref_dlg(dlg,1);
		}

		/* dialog confirmed */
		run_dlg_callbacks( DLGCB_CONFIRMED, dlg, rpl, DLG_DIR_UPSTREAM, 0);

		if (old_state==DLG_STATE_EARLY)
			if_update_stat(dlg_enable_stats, early_dlgs, -1);

		if_update_stat(dlg_enable_stats, active_dlgs, 1);
		return;
	}

	if ( old_state!=DLG_STATE_DELETED && new_state==DLG_STATE_DELETED ) {
		LM_DBG("dialog %p failed (negative reply)\n", dlg);
		

		/*destroy linkers */
		destroy_linkers(dlg->profile_links);
		dlg->profile_links = NULL;

		/* dialog setup not completed (3456XX) */
		run_dlg_callbacks( DLGCB_FAILED, dlg, rpl, DLG_DIR_UPSTREAM, 0);
		/* do unref */
		if (unref)
			unref_dlg(dlg,unref);
		if (old_state==DLG_STATE_EARLY)
			if_update_stat(dlg_enable_stats, early_dlgs, -1);
		return;
	}

	/* in any other case, check if the dialog state machine
	   requests to unref the dialog */
	if (unref)
		unref_dlg(dlg,unref);

	return;
}


static void dlg_seq_up_onreply(struct cell* t, int type,
													struct tmcb_params *param)
{
	struct dlg_cell *dlg;

	dlg = (struct dlg_cell *)(*param->param);
	if (shutdown_done || dlg==0)
		return;

	if (type==TMCB_RESPONSE_FWDED) {
		run_dlg_callbacks(DLGCB_RESPONSE_WITHIN, dlg, param->rpl,
			DLG_DIR_UPSTREAM, 0);
		return;
	}

	return;
}



static void dlg_seq_down_onreply(struct cell* t, int type,
													struct tmcb_params *param)
{
	struct dlg_cell *dlg;

	dlg = (struct dlg_cell *)(*param->param);
	if (shutdown_done || dlg==0)
		return;

	if (type==TMCB_RESPONSE_FWDED) {
		run_dlg_callbacks(DLGCB_RESPONSE_WITHIN, dlg, param->rpl,
			DLG_DIR_DOWNSTREAM, 0);
		return;
	}

	return;
}


inline static int get_dlg_timeout(struct sip_msg *req)
{
	pv_value_t pv_val;

	if( timeout_avp && pv_get_spec_value( req, timeout_avp, &pv_val)==0
	&& pv_val.flags&PV_VAL_INT && pv_val.ri>0 ) {
		return pv_val.ri;
	}
	LM_DBG("invalid AVP value, use default timeout\n");
	return default_timeout;
}


static void unreference_dialog(void *dialog)
{
	/* if the dialog table is gone, it means the system is shutting down.*/
	if (!d_table)
		return;
	unref_dlg((struct dlg_cell*)dialog, 1);
}


static void unreference_dialog_create(void *dialog)
{
	struct tmcb_params params;

	memset(&params, 0, sizeof(struct tmcb_params));
	params.param = (void*)&dialog;
	/* just a wapper */
	dlg_onreply( 0, TMCB_TRANS_DELETED, &params);
}



void dlg_onreq(struct cell* t, int type, struct tmcb_params *param)
{
	/* is the dialog already created? */
	if (current_dlg_pointer!=NULL) {
		/* new, un-initialized dialog ? */
		if ( current_dlg_pointer->flags & DLG_FLAG_ISINIT )
			return;

		/* dialog was previously created by create_dialog() 
		   -> just do the last settings */
		run_create_callbacks( current_dlg_pointer, param->req);

		current_dlg_pointer->lifetime = get_dlg_timeout(param->req);

		if (param->req->flags&bye_on_timeout_flag)
			current_dlg_pointer->flags |= DLG_FLAG_BYEONTIMEOUT;

		t->dialog_ctx = (void*)current_dlg_pointer;

		/* dialog is fully initialized */
		current_dlg_pointer->flags |= DLG_FLAG_ISINIT;
	} else {
		/* should we create dialog? */
		if ( (param->req->flags & dlg_flag) != dlg_flag)
			return;

		/* create the dialog */
		dlg_create_dialog(t, param->req);
	}
}


int dlg_create_dialog(struct cell* t, struct sip_msg *req)
{
	struct dlg_cell *dlg;
	str s;

	if ( (!req->to && parse_headers(req, HDR_TO_F,0)<0) || !req->to ) {
		LM_ERR("bad request or missing TO hdr :-/\n");
		return -1;
	}
	s = get_to(req)->tag_value;
	if (s.s!=0 && s.len!=0)
		return -1;

	if (req->first_line.u.request.method_value==METHOD_CANCEL)
		return -1;

	if ( parse_from_header(req)) {
		LM_ERR("bad request or missing FROM hdr :-/\n");
		return -1;
	}
	if ((!req->callid && parse_headers(req,HDR_CALLID_F,0)<0) || !req->callid){
		LM_ERR("bad request or missing CALLID hdr :-/\n");
		return -1;
	}
	s = req->callid->body;
	trim(&s);

	/* some sanity checks */
	if (s.len==0 || get_from(req)->tag_value.len==0) {
		LM_ERR("invalid request -> callid (%d) or from TAG (%d) empty\n",
			s.len, get_from(req)->tag_value.len);
		return -1;
	}

	dlg = build_new_dlg( &s /*callid*/, &(get_from(req)->uri) /*from uri*/,
		&(get_to(req)->uri) /*to uri*/,
		&(get_from(req)->tag_value)/*from_tag*/ );
	if (dlg==0) {
		LM_ERR("failed to create new dialog\n");
		return -1;
	}

	/* save caller's tag, cseq, contact and record route*/
	if (init_leg_info(dlg, req, t, &(get_from(req)->tag_value) ) !=0) {
		LM_ERR("could not add further info to the dialog\n");
		shm_free(dlg);
		return -1;
	}

	/* set current dialog */
	set_current_dialog(dlg);
	last_dst_leg = DLG_FIRST_CALLEE_LEG;

	link_dlg( dlg , 2/* extra ref for the callback and current dlg hook */);

	if ( seq_match_mode!=SEQ_MATCH_NO_ID &&
	add_dlg_rr_param( req, dlg->h_entry, dlg->h_id)<0 ) {
		LM_ERR("failed to add RR param\n");
		goto error;
	}

	if ( d_tmb.register_tmcb( req, t,
				TMCB_RESPONSE_PRE_OUT|TMCB_RESPONSE_FWDED|TMCB_TRANS_CANCELLED,
				dlg_onreply, (void*)dlg, unreference_dialog_create)<0 ) {
		LM_ERR("failed to register TMCB\n");
		goto error;
	}

	/* complete the dialog setup only if transaction aleady exists;
	   if not, wait for the TMCB_REQUEST_IN callback to do this job */
	if (t) {
		/* first INVITE seen (dialog created, unconfirmed) */
		run_create_callbacks( dlg, req);

		dlg->lifetime = get_dlg_timeout(req);

		if (req->flags&bye_on_timeout_flag)
			dlg->flags |= DLG_FLAG_BYEONTIMEOUT;

		t->dialog_ctx = (void*) dlg;

		dlg->flags |= DLG_FLAG_ISINIT;
	}

	if_update_stat( dlg_enable_stats, processed_dlgs, 1);

	return 0;
error:
	unref_dlg(dlg,1);
	dialog_cleanup( req, NULL);
	update_stat(failed_dlgs, 1);
	return -1;
}



static inline int parse_dlg_rr_param(char *p, char *end,
													int *h_entry, int *h_id)
{
	char *s;

	for ( s=p ; p<end && *p!=DLG_SEPARATOR ; p++ );
	if (*p!=DLG_SEPARATOR) {
		LM_ERR("malformed rr param '%.*s'\n", (int)(long)(end-s), s);
		return -1;
	}

	if ( (*h_entry=reverse_hex2int( s, p-s))<0 ) {
		LM_ERR("invalid hash entry '%.*s'\n", (int)(long)(p-s), s);
		return -1;
	}

	if ( (*h_id=reverse_hex2int( p+1, end-(p+1)))<0 ) {
		LM_ERR("invalid hash id '%.*s'\n", (int)(long)(end-(p+1)), p+1 );
		return -1;
	}

	return 0;
}


static inline int pre_match_parse( struct sip_msg *req, str *callid,
														str *ftag, str *ttag)
{
	if (parse_headers(req,HDR_CALLID_F|HDR_TO_F,0)<0 || !req->callid ||
	!req->to ) {
		LM_ERR("bad request or missing CALLID/TO hdr :-/\n");
		return -1;
	}

	if (get_to(req)->tag_value.len==0) {
		/* out of dialog request with preloaded Route headers; ignore. */
		return -1;
	}

	if (parse_from_header(req)<0 || get_from(req)->tag_value.len==0) {
		LM_ERR("failed to get From header\n");
		return -1;
	}

	/* callid */
	*callid = req->callid->body;
	trim(callid);
	/* to tag */
	*ttag = get_to(req)->tag_value;
	/* from tag */
	*ftag = get_from(req)->tag_value;
	return 0;
}


static inline int update_cseqs(struct dlg_cell *dlg, struct sip_msg *req,
															unsigned int leg)
{
	if ( (!req->cseq && parse_headers(req,HDR_CSEQ_F,0)<0) || !req->cseq ||
	!req->cseq->parsed) {
		LM_ERR("bad sip message or missing CSeq hdr :-/\n");
		return -1;
	}

	return dlg_update_cseq(dlg, leg, &((get_cseq(req))->number));
}


void dlg_onroute(struct sip_msg* req, str *route_params, void *param)
{
	struct dlg_cell *dlg;
	str val;
	str callid;
	str ftag;
	str ttag;
	int h_entry;
	int h_id;
	int new_state;
	int old_state;
	int unref;
	int event;
	int timeout;
	unsigned int dir,dst_leg;
	int ret = 0;

	/* as this callback is triggered from loose_route, which can be 
	   accidentaly called more than once from script, we need to be sure 
	   we do this only once !*/
	if (current_dlg_pointer)
		return;

	/* skip initial requests - they may end up here because of the
	 * preloaded route */
	if ( (!req->to && parse_headers(req, HDR_TO_F,0)<0) || !req->to ) {
		LM_ERR("bad request or missing TO hdr :-/\n");
		return;
	}
	if ( get_to(req)->tag_value.len==0 )
		return;

	dlg = 0;
	dir = DLG_DIR_NONE;
	dst_leg = -1;

	if ( seq_match_mode!=SEQ_MATCH_NO_ID ) {
		if( d_rrb.get_route_param( req, &rr_param, &val)!=0) {
			LM_DBG("Route param '%.*s' not found\n", rr_param.len,rr_param.s);
			if (seq_match_mode==SEQ_MATCH_STRICT_ID )
				return;
		} else {
			LM_DBG("route param is '%.*s' (len=%d)\n",val.len,val.s,val.len);

			if ( parse_dlg_rr_param( val.s, val.s+val.len, &h_entry, &h_id)<0 )
				return;

			dlg = lookup_dlg( h_entry, h_id);
			if (dlg==0) {
				LM_WARN("unable to find dialog for %.*s "
					"with route param '%.*s'\n",
					req->first_line.u.request.method.len,
					req->first_line.u.request.method.s,
					val.len,val.s);
				return;
			}

			/* lookup_dlg has incremented the ref count by 1 */

			if (pre_match_parse( req, &callid, &ftag, &ttag)<0) {
				unref_dlg(dlg, 1);
				return;
			}
			if (match_dialog( dlg, &callid, &ftag, &ttag, &dir, &dst_leg )==0){
				LM_WARN("tight matching failed for %.*s with callid='%.*s'/%d,"
						" ftag='%.*s'/%d, ttag='%.*s'/%d and direction=%d\n",
						req->first_line.u.request.method.len,
						req->first_line.u.request.method.s,
						callid.len, callid.s, callid.len,
						ftag.len, ftag.s, ftag.len,
						ttag.len, ttag.s, ttag.len, dir);
				LM_WARN("dialog identification elements are callid='%.*s'/%d, "
						"caller tag='%.*s'/%d, callee tag='%.*s'/%d\n",
						dlg->callid.len, dlg->callid.s, dlg->callid.len,
						dlg->legs[DLG_CALLER_LEG].tag.len,
						dlg->legs[DLG_CALLER_LEG].tag.s,
						dlg->legs[DLG_CALLER_LEG].tag.len,
						dlg->legs[callee_idx(dlg)].tag.len,
						ZSW(dlg->legs[callee_idx(dlg)].tag.s),
						dlg->legs[callee_idx(dlg)].tag.len);
				unref_dlg(dlg, 1);
				return;
			}
		}
	}

	if (dlg==0) {
		if (pre_match_parse( req, &callid, &ftag, &ttag)<0)
			return;
		/* TODO - try to use the RR dir detection to speed up here the
		 * search -bogdan */
		dlg = get_dlg(&callid, &ftag, &ttag, &dir, &dst_leg);
		if (!dlg){
			LM_DBG("Callid '%.*s' not found\n",
				req->callid->body.len, req->callid->body.s);
			return;
		}
	}

	/* run state machine */
	switch ( req->first_line.u.request.method_value ) {
		case METHOD_PRACK:
			event = DLG_EVENT_REQPRACK; break;
		case METHOD_ACK:
			event = DLG_EVENT_REQACK; break;
		case METHOD_BYE:
			event = DLG_EVENT_REQBYE; break;
		default:
			event = DLG_EVENT_REQ;
	}

	next_state_dlg( dlg, event, &old_state, &new_state, &unref);

	/* set current dialog - it will keep a ref! */
	set_current_dialog(dlg);
	last_dst_leg = dst_leg;

	/* run actions for the transition */
	if (event==DLG_EVENT_REQBYE && new_state==DLG_STATE_DELETED &&
	old_state!=DLG_STATE_DELETED) {
		
		/*destroy linkers */
		destroy_linkers(dlg->profile_links);
		dlg->profile_links = NULL;

		LM_DBG("BYE successfully processed\n");
		/* remove from timer */
		ret = remove_dlg_timer(&dlg->tl);
		if (ret < 0) {
			LM_CRIT("unable to unlink the timer on dlg %p [%u:%u] "
				"with clid '%.*s' and tags '%.*s' '%.*s'\n",
				dlg, dlg->h_entry, dlg->h_id,
				dlg->callid.len, dlg->callid.s,
				dlg->legs[DLG_CALLER_LEG].tag.len,
				dlg->legs[DLG_CALLER_LEG].tag.s,
				dlg->legs[callee_idx(dlg)].tag.len,
				ZSW(dlg->legs[callee_idx(dlg)].tag.s));
		} else if (ret > 0) {
			LM_DBG("dlg expired (not in timer list) on dlg %p [%u:%u] "
				"with clid '%.*s' and tags '%.*s' '%.*s'\n",
				dlg, dlg->h_entry, dlg->h_id,
				dlg->callid.len, dlg->callid.s,
				dlg->legs[DLG_CALLER_LEG].tag.len,
				dlg->legs[DLG_CALLER_LEG].tag.s,
				dlg->legs[callee_idx(dlg)].tag.len,
				ZSW(dlg->legs[callee_idx(dlg)].tag.s));
		} else {
			/* dialog sucessfully removed from timer -> unref */
			unref++;
		}
		/* dialog terminated (BYE) */
		run_dlg_callbacks( DLGCB_TERMINATED, dlg, req, dir, 0);

		/* delete the dialog from DB */
		if (should_remove_dlg_db())
			remove_dialog_from_db(dlg);

		/* destroy dialog */
		unref_dlg(dlg, unref);

		if_update_stat( dlg_enable_stats, active_dlgs, -1);
		return;
	}

	if ( (event==DLG_EVENT_REQ || event==DLG_EVENT_REQACK)
	&& new_state==DLG_STATE_CONFIRMED) {
		LM_DBG("sequential request successfully processed (dst_leg=%d)\n",
			dst_leg);
		timeout = get_dlg_timeout(req);
		/* update timer during sequential request? */
		if (timeout!=default_timeout) {
			dlg->lifetime = timeout;
			if (update_dlg_timer( &dlg->tl, dlg->lifetime )==-1)
				LM_ERR("failed to update dialog lifetime\n");
		}
		if ( event!=DLG_EVENT_REQACK ) {
			if (dst_leg==-1 || update_cseqs(dlg, req, dst_leg)!=0) {
				LM_ERR("cseqs update failed on leg=%d\n",dst_leg);
			} else {
				dlg->flags |= DLG_FLAG_CHANGED;
				if ( dlg_db_mode==DB_MODE_REALTIME )
					update_dialog_dbinfo(dlg);
			}
		}

		/* within dialog request */
		run_dlg_callbacks( DLGCB_REQ_WITHIN, dlg, req, dir, 0);

		if ( (event!=DLG_EVENT_REQACK) &&
		(dlg->cbs.types)&DLGCB_RESPONSE_WITHIN ) {
			/* ref the dialog as registered into the transaction callback.
			 * unref will be done when the callback will be destroyed */
			ref_dlg( dlg , 1);
			/* register callback for the replies of this request */
			if ( d_tmb.register_tmcb( req, 0, TMCB_RESPONSE_FWDED,
			(dir==DLG_DIR_UPSTREAM)?dlg_seq_down_onreply:dlg_seq_up_onreply,
			(void*)dlg, unreference_dialog)<0 ) {
				LM_ERR("failed to register TMCB (2)\n");
					unref_dlg( dlg , 1);
			}
		}
	}

	if ( event==DLG_EVENT_REQPRACK && new_state==DLG_STATE_EARLY) {
		LM_DBG("PRACK successfully processed (dst_leg=%d)\n",dst_leg);
		if (dst_leg==-1 || update_cseqs(dlg, req, dst_leg)!=0)
			LM_ERR("cseqs update failed on leg=%d\n",dst_leg);
	}

	if(new_state==DLG_STATE_CONFIRMED && old_state==DLG_STATE_CONFIRMED_NA){
		dlg->flags |= DLG_FLAG_CHANGED;
		if(dlg_db_mode == DB_MODE_REALTIME)
			update_dialog_dbinfo(dlg);
	}

	return;
}



#define get_dlg_tl_payload(_tl_)  ((struct dlg_cell*)((char *)(_tl_)- \
		(unsigned long)(&((struct dlg_cell*)0)->tl)))

/* When done, this function also has the job to unref the dialog as removed
 * from timer list. This must be done in all cases!!
 */
void dlg_ontimeout( struct dlg_tl *tl)
{
	struct dlg_cell *dlg;
	int new_state;
	int old_state;
	int unref;

	dlg = get_dlg_tl_payload(tl);

	if ( (dlg->flags&DLG_FLAG_BYEONTIMEOUT) &&
	(dlg->state==DLG_STATE_CONFIRMED_NA || dlg->state==DLG_STATE_CONFIRMED)) {
		/* we just send the BYEs in both directions */
		dlg_end_dlg( dlg, NULL);
		/* dialog is no longer refed by timer; from now one it is refed
		   by the send_bye functions */
		unref_dlg( dlg, 1);
		/* is not 100% sure, but do it */
		if_update_stat( dlg_enable_stats, expired_dlgs, 1);
		return ;
	}

	next_state_dlg( dlg, DLG_EVENT_REQBYE, &old_state, &new_state, &unref);

	if (new_state==DLG_STATE_DELETED && old_state!=DLG_STATE_DELETED) {
		LM_DBG("timeout for dlg with CallID '%.*s' and tags '%.*s' '%.*s'\n",
			dlg->callid.len, dlg->callid.s,
			dlg->legs[DLG_CALLER_LEG].tag.len,
			dlg->legs[DLG_CALLER_LEG].tag.s,
			dlg->legs[callee_idx(dlg)].tag.len,
			ZSW(dlg->legs[callee_idx(dlg)].tag.s));

		/*destroy linkers */
		destroy_linkers(dlg->profile_links);
		dlg->profile_links = NULL;

		/* dialog timeout */
		run_dlg_callbacks( DLGCB_EXPIRED, dlg, 0, DLG_DIR_NONE, 0);

		/* delete the dialog from DB */
		if (should_remove_dlg_db())
			remove_dialog_from_db(dlg);

		unref_dlg(dlg, unref + 1 /*timer list*/);

		if_update_stat( dlg_enable_stats, expired_dlgs, 1);
		if_update_stat( dlg_enable_stats, active_dlgs, -1);
	} else {
		unref_dlg(dlg, 1 /*just timer list*/);
	}

	return;
}


int dlg_validate_dialog( struct sip_msg* req, struct dlg_cell *dlg)
{
	struct dlg_leg *leg;
	unsigned int n,m;
	struct sip_uri curi;
	int r_proto, c_proto, r_port, c_port;
	str s;

	if (last_dst_leg<0) {
		LM_ERR("Script error - validate function before having a dialog\n");
		return -1;
	}

	leg = & dlg->legs[ last_dst_leg ];


	/* first check the cseq (if it's increasing) */
	if ( (!req->cseq && parse_headers(req,HDR_CSEQ_F,0)<0) || !req->cseq ||
	!req->cseq->parsed) {
		LM_ERR("bad sip message or missing CSeq hdr :-/\n");
		return -1;
	}

	n = m = 0;
	if ( str2int( &((get_cseq(req))->number), &n)!=0 ||
	str2int( &(leg->r_cseq), &n)!=0 || n<=m ) {
		LM_DBG("cseq test falied recv=%d, old=%d\n",n,m);
		return -1;
	}

	if (dlg->state <= DLG_STATE_EARLY)
		return 0;

	/* check the RURI - it must be the contact of the destination leg */
	/* after loose_route() even if the previous hop was a strict router,
	   opensips will set in RURI the remote contact */
	if ( parse_sip_msg_uri(req)<0 ||
	parse_uri( leg->contact.s, leg->contact.len, &curi)!=0 ) {
		LM_ERR("failed to parse RURI/Contacts\n");
		return -1;
	}
	/* check proto */
	r_proto = (req->parsed_uri.proto==PROTO_NONE) ?
		PROTO_UDP : req->parsed_uri.proto;
	c_proto = (curi.proto==PROTO_NONE) ?
		PROTO_UDP : curi.proto;
	if ( r_proto!=c_proto ) {
		s = *GET_RURI(req);
		LM_DBG("RURI/Contact PROTO test failed ruri=[%.*s], old=[%.*s]\n",
			s.len,s.s,leg->contact.len,leg->contact.s);
		return -1;
	}
	/* check port */
	r_port=(req->parsed_uri.port_no==0) ?
		( (r_proto==PROTO_TLS)?5061:5060) : req->parsed_uri.port_no ;
	c_port=(curi.port_no==0) ?
		( (c_proto==PROTO_TLS)?5061:5060) : curi.port_no ;
	if ( r_port!=c_port ) {
		s = *GET_RURI(req);
		LM_DBG("RURI/Contact PORT test failed ruri=[%.*s], old=[%.*s]\n",
			s.len,s.s,leg->contact.len,leg->contact.s);
		return -1;
	}
	/* host (as string) */
	if ( curi.host.len!=req->parsed_uri.host.len ||
	memcmp(req->parsed_uri.host.s, curi.host.s, curi.host.len)!=0 ) {
		s = *GET_RURI(req);
		LM_DBG("RURI/Contact HOST test failed ruri=[%.*s], old=[%.*s]\n",
			s.len,s.s,leg->contact.len,leg->contact.s);
		return -1;
	}

	/* check the route set - is the the same as in original request */
	/* the route set (without the first Route) must be the same as the
	   one stored in the destination leg */
	/* extract the RR parts */
	if( parse_headers( req, HDR_EOH_F, 0)<0 ) {
		LM_ERR("failed to parse headers when looking after ROUTEs\n");
		return -1;
	}
	if ( req->route==NULL) {
		if ( leg->route_set.len!=0) {
			LM_DBG("route check failed (req has no route, but dialog has\n");
			return -1;
		}
	} else {
		m = 1; /*skip first*/
		if( print_rr_body( req->route, &s, 0/*normal oder*/, &m/*skip*/)!=0 ) {
			LM_ERR("failed to print route headers\n");
			return -1;
		}
		if ( s.len!=leg->route_set.len || memcmp(leg->route_set.s,s.s,s.len)){
			LM_DBG("route check failed req=[%.*s] dlg=[%.*s]\n",
				s.len,s.s,leg->route_set.len,leg->route_set.s);
			pkg_free(s.s);
			return -1;
		}
		pkg_free(s.s);
	}

	return 0;
}


