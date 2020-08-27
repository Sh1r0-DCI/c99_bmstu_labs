#include <stdio.h>
#include "funcs.h"
#include "error_code.h"

int main(void)
{
    setbuf(stdout, NULL);
    int ci;
    int arr[N];
    int n, ans = 1;
	ci = array_input(arr, &n);
    if (ci == INPUT_ERROR)
        printf("Input error.");
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