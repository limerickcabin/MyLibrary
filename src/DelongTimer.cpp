/*
Simple Arduino timer class to simplify state machine timing
while avoiding delays
*/

#include <Arduino.h>
#include "DelongTimer.h"

milliTimer::milliTimer(void) {
      msTimer=millis();
}

void milliTimer::set(int32_t msFromNow) {
      msTimer=millis()+msFromNow;
}

void milliTimer::add(int32_t msExtraTime) {
      msTimer+=msExtraTime;
}

boolean milliTimer::isExpired(void) {
      return ((int32_t)millis()-msTimer)>0;
}

