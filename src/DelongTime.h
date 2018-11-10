#define TIMEZONE (-7)

// ascii time stamp tied to NTP
char timebuf[80];
char * gettime(void) {
  time_t snap;
  time(&snap);
  strcpy(timebuf,ctime(&snap));
  //*strstr(timebuf,"\n")=0;
  strncpy(timebuf, timebuf+11, 8);
  timebuf[5]=0;
  return timebuf;
}

void setupTime(void) {
  configTime(TIMEZONE*3600, 0, "pool.ntp.org");
}

