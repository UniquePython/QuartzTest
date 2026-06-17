#ifndef QUARTZ_H_
#define QUARTZ_H_

typedef struct quartz_test_result_t QuartzTestResult;

QuartzTestResult *quartzTestResultNew(void);
void quartzTestResultFree(QuartzTestResult **quartzTestResult);

#endif
