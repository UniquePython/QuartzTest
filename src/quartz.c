#include "quartz.h"

#include <stdlib.h>

typedef struct quartz_location_t
{
    const char *file;
    const char *func;
    unsigned int line;
} QuartzLocation;

struct quartz_test_result_t
{
    bool pass;
    QuartzLocation loc;
    const char *expr;
};

QuartzTestResult *quartzTestResultNew(void)
{
    QuartzTestResult *quartzTestResult = malloc(sizeof(QuartzTestResult));
    if (!quartzTestResult)
        return NULL;

    quartzTestResult->pass = false;
    quartzTestResult->loc = (QuartzLocation){0};
    quartzTestResult->expr = NULL;

    return quartzTestResult;
}

void quartzTestResultFree(QuartzTestResult **quartzTestResult)
{
    if (quartzTestResult && *quartzTestResult)
    {
        free(*quartzTestResult);
        *quartzTestResult = NULL;
    }
}

void quartzAssert(bool cond, QuartzTestResult *result, const char *file, const char *func, unsigned int line, const char *expr)
{
    if (result && cond == false && result->pass != false)
    {
        result->pass = cond;
        result->loc = (QuartzLocation){file, func, line};
        result->expr = expr;
    }
}
