#ifndef delongtime_h
#define delongtime_h

#define TIMEZONE (-8)

// ascii time stamp tied to NTP
char timebuf[80];
char * gettime(void) {
  time_t snap;
  time(&snap);
  strcpy(timebuf,ctime(&snap));
  //*strstr(timebuf,"\n")=0;
  strncpy(timebuf, timebuf+11, 8);
  timebuf[8]=0;
  return timebuf;
}

void setupTime(void) {
  configTime(TIMEZONE*3600, 0, "pool.ntp.org");
}
#endif
