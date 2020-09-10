#include "funcs.h"

int array_change(int arr[], int n)
{
    int num_of_multiple_of_three = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 3 == 0)
            insert_num(arr, n++, fib(num_of_multiple_of_three++), ++i);
    }
    return n;
}

void insert_num(int arr[], int n, int a, int k)
{
    for (int i = n; i > k; i--)
        arr[i] = arr[i - 1];
    arr[k] = a;
}

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return (fib(n - 1) + fib(n - 2));
}