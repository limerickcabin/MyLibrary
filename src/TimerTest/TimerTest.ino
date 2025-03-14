/*
 * Arduino sketch to test updates I did to DeLongTimer
 */
#include "DelongTimer.h"
milliTimer timer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  Serial.printf("\n**********************\n%s %s %s\n",__FILE__,__DATE__,__TIME__);
  
  if (timer.doTests()) Serial.println("test OK");
  else Serial.println("tests failed");
}

void loop() {
  // put your main code here, to run repeatedly:
}