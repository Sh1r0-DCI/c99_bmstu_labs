#include <stdio.h>
#include "funcs.h"
#include "error_code.h"

int main(void)
{
    setbuf(stdout, NULL);
    int ci;
    int arr[N], new_arr[N];
    int n, new_n;
    ci = array_input(arr, &n);
    if (ci == INPUT_ERROR)
        printf("Input error.");
    else
    {
        new_n = making_prime_num_array(arr, new_arr, n);
        if (!new_n)
        {
            printf("No prime numbers in array.");
            ci = NO_PRIMES_IN_ARRAY;
        }
    }
    if (ci == OK)
        array_output(new_arr, new_n);
    return ci;
}