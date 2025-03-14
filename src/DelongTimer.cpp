/*
Simple Arduino timer class to simplify state machine timing
in order to avoid using blocking delay functions
*/

#include <Arduino.h>
#include "DelongTimer.h"

milliTimer::milliTimer(void) {
      milliTimer(0);
}

milliTimer::milliTimer(uint64_t msFromNow) {
      msTimer=millis()+msFromNow;
	  rolloverAdder=0;
	  lastNow=msTimer;
}

void milliTimer::set(uint64_t msFromNow) {
      msTimer=llmillis()+msFromNow;
}

void milliTimer::add(uint64_t msExtraTime) {
      msTimer+=msExtraTime;
}

bool milliTimer::isExpired(void){
      return (llmillis()>msTimer);					//expired if now is newer than timer
}

//returns 64 bit number of milliseconds (if called at least every few weeks)
uint64_t milliTimer::llmillis(void) {
      uint64_t now=millis();
	  if (lastNow>now) {
		  rolloverAdder+=4294967296ll; 				//32 bit timer rolled over
	  }
	  lastNow=now;
	  uint64_t bigNow=now+rolloverAdder; 			//64 bit milliseconds (millions of years)
	  return(bigNow);
}

//tests
void milliTimer::rollover(void) {
	lastNow=millis()+10000; 
}


bool milliTimer::doTests(void) {
	milliTimer();
	uint64_t t;
	bool success=true;
	
	//test rollover
	t=llmillis();
	rollover();
	t=llmillis()-t;
	if (t<4000000000) success=false;

	//test set
	set(100);
	delay(50);
	if (isExpired()) success=false;
	delay(60);
	if (!isExpired()) success=false;

	//test add
	add(100);
	if (isExpired()) success=false;
	delay(110);
	if (!isExpired()) success=false;

	return(success);
}
