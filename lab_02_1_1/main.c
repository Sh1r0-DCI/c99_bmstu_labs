#include <stdio.h>
#include "funcs.h"

int main(void)
{
    setbuf(stdout, NULL);
    int rc, ci = OK;
    int arr[N];
    int n, ans;
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
        ans = odd_multiplication(arr, n);
        if (ans == NO_ODD_ELEMENTS)
        {
            printf("No odd elements in array.");
			ci = NO_ODD_ELEMENTS;
        }
    }
    if (ci == OK)
        printf("%d", ans);
    return ci;
}