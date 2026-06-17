#ifndef QUARTZ_H_
#define QUARTZ_H_

#include <stdbool.h>

typedef struct quartz_test_result_t QuartzTestResult;

QuartzTestResult *quartzTestResultNew(void);
void quartzTestResultFree(QuartzTestResult **quartzTestResult);

void quartzAssert(bool cond, QuartzTestResult *result, const char *file, const char *func, unsigned int line, const char *expr);
#define ASSERT(cond) quartzAssert((cond), result, __FILE__, __func__, __LINE__, #cond)

#endif
