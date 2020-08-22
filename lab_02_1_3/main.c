#include <stdio.h>
#include "funcs.h"

int main(void)
{
    setbuf(stdout, NULL);
    int rc, ci = OK;
    int arr[N];
    int n, new_n;
    printf("Input n - array size: ");
    rc = scanf("%d", &n);
    if (rc != 1)
    {
        printf("Input error.");
        ci = INPUT_ERROR;
    }
    else if (array_input(arr, n) == INPUT_ERROR)
    {
        printf("Incorrect input of array.");
        ci = INPUT_ERROR;
    }
    else
    {
        new_n = n + array_change(arr, n);
        /*if (new_n == n)
        {
            printf("No miltiples of three in array.");
            ci = NO_MULTIPLES_OF_THREE_IN_ARRAY;
        }*/
    }
    if (ci == OK)
        array_output(arr, new_n);
    return ci;
}