#ifndef milliTimer_h
#define milliTimer_h


class milliTimer {
  public:
    milliTimer(void);
    milliTimer(uint64_t msFromNow); 
    void set(uint64_t msFromNow);
    void add(uint64_t msExtraTime);
    bool isExpired(void);
	uint64_t llmillis(void);
	bool doTests(void);
  private:
    uint64_t msTimer;
	uint64_t rolloverAdder;
	uint32_t lastNow;
	void rollover(void);
};
#endif
