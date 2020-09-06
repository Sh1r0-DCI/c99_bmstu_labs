#include <stdio.h>
#include "in_out.h"
#include "error_code.h"

int array_input(int *pa_start, int **pa_end)
{
    int rc, n;
    printf("Input n - array size: ");
    rc = scanf("%d", &n);
    if (rc != 1)
        return INPUT_ERROR;
    else if (n > MAX_N || n < MIN_N)
    {
        return N_IS_OF_WRONG_VALUE;
    }
    *pa_end = pa_start + n;
    printf("Input n elements:\n");
    for (int* pa = pa_start; pa != *pa_end; pa++)
    {
        rc = scanf("%d", pa);
        if (rc != 1)
            return INPUT_ERROR;
    }
    return OK;
}