#include <stdio.h>
#include "funcs.h"

int main(void)
{
    setbuf(stdout, NULL);
    int rc, ci;
    int arr[N];
    int n, ans = 1;
    printf("Input n - array size: ");
    rc = scanf("%d", &n);
    if (rc != 1)
    {
        printf("Input error.");
        ci = INPUT_ERROR;
    }
    else if ((ci = array_input(arr, n)) == INPUT_ERROR)
        printf("Incorrect input of array.");
    else
    {
        ci = odd_multiplication(arr, n, &ans);
        if (ci == NO_ODD_ELEMENTS)
            printf("No odd elements in array.");
    }
    if (ci == OK)
        printf("%d", ans);
    return ci;
}