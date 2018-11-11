#ifndef delongtime_h
#define delongtime_h

// ascii time stamp tied to NTP
char _timebuf[80];
char * gettime(void) {
  time_t snap;
  time(&snap);
  strcpy(_timebuf,ctime(&snap));
  //*strstr(timebuf,"\n")=0;
  strncpy(_timebuf, _timebuf+11, 8);
  _timebuf[8]=0;
  return _timebuf;
}

void setupTime(int timezone) {
  configTime(timezone*3600, 0, "pool.ntp.org");
}
#endif
