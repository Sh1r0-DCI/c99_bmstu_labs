#include "funcs.h"

int max_sum(int *const pa_start, int *const pa_end)
{
    const int *pa = pa_start;
    const int *pa_backwards = pa_end;
    int sum = *pa_start + *(pa_end - 1);
    for (int i = 0; i <= (pa_end - pa_start - 1) / 2; i++, pa++)
    {
        if (*pa + *pa_backwards-- > sum)
            sum = *pa + *pa_backwards;
    }
    return sum;
}