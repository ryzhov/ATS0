/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.36
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.pjsip.pjsua;

public class pjmedia_codec_fmtp_param {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected pjmedia_codec_fmtp_param(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(pjmedia_codec_fmtp_param obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      pjsuaJNI.delete_pjmedia_codec_fmtp_param(swigCPtr);
    }
    swigCPtr = 0;
  }

  public void setName(pj_str_t value) {
    pjsuaJNI.pjmedia_codec_fmtp_param_name_set(swigCPtr, this, pj_str_t.getCPtr(value), value);
  }

  public pj_str_t getName() {
    long cPtr = pjsuaJNI.pjmedia_codec_fmtp_param_name_get(swigCPtr, this);
    return (cPtr == 0) ? null : new pj_str_t(cPtr, false);
  }

  public void setVal(pj_str_t value) {
    pjsuaJNI.pjmedia_codec_fmtp_param_val_set(swigCPtr, this, pj_str_t.getCPtr(value), value);
  }

  public pj_str_t getVal() {
    long cPtr = pjsuaJNI.pjmedia_codec_fmtp_param_val_get(swigCPtr, this);
    return (cPtr == 0) ? null : new pj_str_t(cPtr, false);
  }

  public pjmedia_codec_fmtp_param() {
    this(pjsuaJNI.new_pjmedia_codec_fmtp_param(), true);
  }

}
