#include <Arduino.h>
#include "DelongTimer.h"

void milliTimer::set(int32_t msFromNow) {
      msTimer=millis()+msFromNow;
}

void milliTimer::add(int32_t msExtraTime) {
      msTimer+=msExtraTime;
}

boolean milliTimer::isExpired(void) {
      return ((int32_t)millis()-msTimer)>0;
}

