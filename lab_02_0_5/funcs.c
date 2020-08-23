#include <stdio.h>
#include "funcs.h"

int array_input(int *pa, int *const pa_start, int *const pa_end)
{
    int rc;
    printf("Input n elements:\n");
    for (int i = 0; i < pa_end - pa_start; i++, pa++)
    {
        rc = scanf("%d", pa);
        if (rc != 1)
            return INPUT_ERROR;
    }
    return OK;
}

int max_sum(int *pa, int *const pa_start, int *const pa_end)
{
    int sum = *pa_start + *(pa_end - 1);
    for (int i = 0; i <= (pa_end - pa_start - 1) / 2; i++, pa++)
    {
        int* pa_backwards = pa_end;
        pa_backwards--;
        for (int j = pa_end - pa_start - 1; j >= (pa_end - pa_start - i - 1); j--)
            pa_backwards--;
        pa_backwards++;
        if (*pa + *pa_backwards > sum)
            sum = *pa + *pa_backwards;
    }
    return sum;
}