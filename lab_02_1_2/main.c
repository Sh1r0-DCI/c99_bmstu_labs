#include <stdio.h>
#include "funcs.h"

int main(void)
{
    setbuf(stdout, NULL);
    int rc, ci = OK;
    int arr[N], new_arr[N];
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
        new_n = making_prime_num_array(arr, new_arr, n);
        if (new_n++ == NO_PRIMES_IN_ARRAY)
        {
            printf("No prime numbers in array.");
            ci = NO_PRIMES_IN_ARRAY;
        }
    }
    if (ci == OK)
        array_output(new_arr, new_n);
    return ci;
}