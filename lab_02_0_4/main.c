#include <stdio.h>
#include "funcs.h"
#include "in_out.h"
#include "error_code.h"

int main(void)
{
    setbuf(stdout, NULL);
    int ci;
    int arr[N];
    int n;
    ci = array_input(arr, &n);
    if (ci == INPUT_ERROR)
        printf("Input error.");
    else if (ci == N_IS_OF_WRONG_VALUE)
        printf("n is of wrong value");
    else
    {
        bubble_sort(arr, n);
        array_output(arr, n);
    }
    return ci;
}