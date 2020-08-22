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

int array_change(int arr[], int n)
{
    int pre_prev_fib = 0, prev_fib = 1, j = 0;
    int num_of_multiples_of_three = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 3 == 0)
        {
            num_of_multiples_of_three++;
            if (j == 0)
                insert_num(arr, ++n, pre_prev_fib, ++i);
            else if (j == 1)
                insert_num(arr, ++n, prev_fib, ++i);
            else
            {
                insert_num(arr, ++n, pre_prev_fib + prev_fib, ++i);
                prev_fib += pre_prev_fib;
                pre_prev_fib = prev_fib - pre_prev_fib;
            }
            j++;
        }
    }
    return num_of_multiples_of_three;
}

void insert_num(int arr[], int n, int a, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (i == k)
        {
            for (int j = i; j < n; j++)
            {
                int temp = arr[j];
                arr[j] = a;
                a = temp;
            }
        }
    }
}

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return (fib(n - 1) + fib(n - 2));
}