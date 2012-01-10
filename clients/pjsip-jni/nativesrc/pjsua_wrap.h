/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.36
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_pjsua_WRAP_H_
#define SWIG_pjsua_WRAP_H_

class SwigDirector_Callback : public Callback, public Swig::Director {

public:
    void swig_connect_director(JNIEnv *jenv, jobject jself, jclass jcls, bool swig_mem_own, bool weak_global);
    SwigDirector_Callback(JNIEnv *jenv);
    virtual ~SwigDirector_Callback();
    virtual void on_call_state(pjsua_call_id call_id, pjsip_event *e);
    virtual void on_call_state_extended(pjsua_call_id call_id, pjsip_event *e, pjsua_call_info *info);
    virtual void on_incoming_call(pjsua_acc_id acc_id, pjsua_call_id call_id, pjsip_rx_data *rdata);
    virtual void on_call_tsx_state(pjsua_call_id call_id, pjsip_transaction *tsx, pjsip_event *e);
    virtual void on_call_media_state(pjsua_call_id call_id);
    virtual void on_stream_created(pjsua_call_id call_id, pjmedia_session *sess, unsigned int stream_idx, pjmedia_port **pm_port);
    virtual void on_stream_destroyed(pjsua_call_id call_id, pjmedia_session *sess, unsigned int stream_idx);
    virtual void on_dtmf_digit(pjsua_call_id call_id, int digit);
    virtual void on_call_transfer_request(pjsua_call_id call_id, pj_str_t const *dst, pjsip_status_code *code);
    virtual void on_call_transfer_status(pjsua_call_id call_id, int st_code, pj_str_t const *st_text, pj_bool_t final_, pj_bool_t *p_cont);
    virtual void on_call_replace_request(pjsua_call_id call_id, pjsip_rx_data *rdata, int *st_code, pj_str_t *st_text);
    virtual void on_call_replaced(pjsua_call_id old_call_id, pjsua_call_id new_call_id);
    virtual void on_reg_state(pjsua_acc_id acc_id);
    virtual void on_reg_state2(pjsua_acc_id acc_id, pjsua_reg_info *info);
    virtual void on_incoming_subscribe(pjsua_acc_id acc_id, pjsua_srv_pres *srv_pres, pjsua_buddy_id buddy_id, pj_str_t const *from, pjsip_rx_data *rdata, pjsip_status_code *code, pj_str_t *reason, pjsua_msg_data *msg_data);
    virtual void on_srv_subscribe_state(pjsua_acc_id acc_id, pjsua_srv_pres *srv_pres, pj_str_t const *remote_uri, pjsip_evsub_state state, pjsip_event *event);
    virtual void on_buddy_state(pjsua_buddy_id buddy_id);
    virtual void on_buddy_evsub_state(pjsua_buddy_id buddy_id, pjsip_evsub *sub, pjsip_event *event);
    virtual void on_pager(pjsua_call_id call_id, pj_str_t const *from, pj_str_t const *to, pj_str_t const *contact, pj_str_t const *mime_type, pj_str_t const *body);
    virtual void on_pager2(pjsua_call_id call_id, pj_str_t const *from, pj_str_t const *to, pj_str_t const *contact, pj_str_t const *mime_type, pj_str_t const *body, pjsip_rx_data *rdata, pjsua_acc_id acc_id);
    virtual void on_pager_status(pjsua_call_id call_id, pj_str_t const *to, pj_str_t const *body, pjsip_status_code status, pj_str_t const *reason);
    virtual void on_pager_status2(pjsua_call_id call_id, pj_str_t const *to, pj_str_t const *body, pjsip_status_code status, pj_str_t const *reason, pjsip_tx_data *tdata, pjsip_rx_data *rdata, pjsua_acc_id acc_id);
    virtual void on_typing(pjsua_call_id call_id, pj_str_t const *from, pj_str_t const *to, pj_str_t const *contact, pj_bool_t is_typing);
    virtual void on_typing2(pjsua_call_id call_id, pj_str_t const *from, pj_str_t const *to, pj_str_t const *contact, pj_bool_t is_typing, pjsip_rx_data *rdata, pjsua_acc_id acc_id);
    virtual void on_nat_detect(pj_stun_nat_detect_result const *res);
    virtual pjsip_redirect_op on_call_redirected(pjsua_call_id call_id, pjsip_uri const *target, pjsip_event const *e);
    virtual void on_mwi_info(pjsua_acc_id acc_id, pjsua_mwi_info *mwi_info);
    virtual void on_ice_transport_error(int index, pj_ice_strans_op op, pj_status_t status);
public:
    bool swig_overrides(int n) {
      return (n < 28 ? swig_override[n] : false);
    }
protected:
    bool swig_override[28];
};


#endif