/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.36
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.pjsip.pjsua;

public enum pjmedia_aud_dev_route {
  PJMEDIA_AUD_DEV_ROUTE_DEFAULT(pjsuaJNI.PJMEDIA_AUD_DEV_ROUTE_DEFAULT_get()),
  PJMEDIA_AUD_DEV_ROUTE_LOUDSPEAKER(pjsuaJNI.PJMEDIA_AUD_DEV_ROUTE_LOUDSPEAKER_get()),
  PJMEDIA_AUD_DEV_ROUTE_EARPIECE(pjsuaJNI.PJMEDIA_AUD_DEV_ROUTE_EARPIECE_get()),
  PJMEDIA_AUD_DEV_ROUTE_BLUETOOTH(pjsuaJNI.PJMEDIA_AUD_DEV_ROUTE_BLUETOOTH_get());

  public final int swigValue() {
    return swigValue;
  }

  public static pjmedia_aud_dev_route swigToEnum(int swigValue) {
    pjmedia_aud_dev_route[] swigValues = pjmedia_aud_dev_route.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (pjmedia_aud_dev_route swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + pjmedia_aud_dev_route.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private pjmedia_aud_dev_route() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private pjmedia_aud_dev_route(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private pjmedia_aud_dev_route(pjmedia_aud_dev_route swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

