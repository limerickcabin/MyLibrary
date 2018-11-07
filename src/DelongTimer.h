#ifndef milliTimer_h
#define milliTimer_h


class milliTimer {
  public:
    milliTimer(void);
    void set(int32_t msFromNow);
    void add(int32_t msExtraTime);
    boolean isExpired(void);
  private:
    int32_t msTimer;
};
#endif
