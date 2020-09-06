#include <stdio.h>
#include "in_out.h"
#include "error_code.h"

int array_input(int arr[], int *pn)
{
    int rc;
    printf("Input n - array size: ");
    rc = scanf("%d", pn);
    if (rc != 1)
        return INPUT_ERROR;
    else if (*pn > MAX_N || *pn < MIN_N)
    {
        return N_IS_OF_WRONG_VALUE;
    }
    printf("Input n elements:\n");
    for (int i = 0; i < *pn; i++)
    {
        rc = scanf("%d", &arr[i]);
        if (rc != 1)
            return INPUT_ERROR;
    }
    return OK;
}

void array_output(const int arr[], int n)
{
    printf("array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}