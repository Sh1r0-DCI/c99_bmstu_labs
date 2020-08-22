#include <stdio.h>
#include "funcs.h"

int main(void)
{
    setbuf(stdout, NULL);
    int rc, ci = OK;
    int arr[N];
    int n;
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
    else if (array_input(arr, n) == INPUT_ERROR)
    {
        printf("Incorrect input of array.");
        ci = INPUT_ERROR;
    }
    else
        bubble_sort(arr, n);
    if (ci == OK)
        array_output(arr, n);
    return ci;
}