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

void array_output(int arr[], int n)
{
    printf("array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}