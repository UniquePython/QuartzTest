#include "quartz.h"

#include <stdbool.h>
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
