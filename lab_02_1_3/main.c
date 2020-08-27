#include <stdio.h>
#include "funcs.h"
#include "error_code.h"

int main(void)
{
    setbuf(stdout, NULL);
    int ci;
    int arr[N];
    int n, new_n;
    ci = array_input(arr, &n);
    if (ci == INPUT_ERROR)
        printf("Input error.");
    else if (ci == N_IS_OF_WRONG_VALUE)
        printf("n is of wrong value");
    else
    {
        new_n = n + array_change(arr, n);
        array_output(arr, new_n);
    }
    return ci;
}