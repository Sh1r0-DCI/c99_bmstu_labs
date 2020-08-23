#include <stdio.h>
#include "funcs.h"

int main()
{
    setbuf(stdout, NULL);
    int rc, ci = OK;
    int a[N];
    int n;
    int *pa = a;
    printf("Input n - array size: ");
    rc = scanf("%d", &n);
    if (rc != 1)
    {
        printf("Input error.");
        ci = INPUT_ERROR;
    }
    else if (n > 10 || n < 1)
    {
        printf("n is of wrong value.");
        ci = N_IS_OF_WRONG_VALUE;
    }
    else
    {
        int *const pa_start = a, *const pa_end = a + n;
        if (array_input(pa, pa_start, pa_end) == INPUT_ERROR)
        {
            printf("Incorrect input of array.");
            ci = INPUT_ERROR;
        }
        else
            printf("max sum: %d\n", max_sum(pa, pa_start, pa_end));
    }
    return ci;
}