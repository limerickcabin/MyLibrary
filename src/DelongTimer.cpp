/*
Simple Arduino timer class to simplify state machine timing
in order to avoid using delay functions
*/

#include <Arduino.h>
#include "DelongTimer.h"

milliTimer::milliTimer(void) {
      msTimer=millis();
}

milliTimer::milliTimer(int32_t msFromNow) {
      msTimer=millis()+msFromNow;
}

void milliTimer::set(int32_t msFromNow) {
      msTimer=millis()+msFromNow;
}

void milliTimer::add(int32_t msExtraTime) {
      msTimer+=msExtraTime;
}

boolean milliTimer::isExpired(void) {
      int32_t now=(int32_t)millis();
      boolean flag = (now-msTimer)>=0;
      if ((now-msTimer)<-2,000,000,000) msTimer=now; // keep it expired
      return flag;
}

