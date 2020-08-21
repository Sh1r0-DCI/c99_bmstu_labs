#include <stdio.h>
#include "funcs.h"

int array_input(int arr[], int n)
{
    int rc;
    printf("Input n elements:\n");
    for (int i = 0; i < n; i++)
    {
        rc = scanf("%d", &arr[i]);
        if (rc != 1)
            return INPUT_ERROR;
    }
    return OK;
}

int odd_multiplication(int arr[], int n)
{
    int ans = 1, odd_els = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            ans *= arr[i];
            odd_els += 1;
        }
    }
    if (odd_els == 0)
        return NO_ODD_ELEMENTS;
    return ans;
}