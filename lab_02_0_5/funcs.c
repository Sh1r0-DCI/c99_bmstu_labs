#include "funcs.h"

int max_sum(int *const pa_start, int *const pa_end)
{
    const int *pa = pa_start;
    const int *pa_backwards = pa_end - 1;
    int sum = *pa_start + *pa_backwards;
    for (; pa < pa_end; pa++, pa_backwards--)
    {
        if (*pa + *pa_backwards > sum)
            sum = *pa + *pa_backwards;
    }
    return sum;
}
//