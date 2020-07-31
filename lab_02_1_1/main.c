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
    if (array_input(arr, n) == INPUT_ERROR)
    {
        printf("Incorrect input of array.");
        ci = INPUT_ERROR;
    }
    if (ci == OK)
        printf("%d", odd_multiplication(arr, n));
    return ci;
}
