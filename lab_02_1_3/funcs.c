#include "funcs.h"
#include "error_code.h"

int array_change(int arr[], int n)
{
    int num_of_multiple_of_three = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 3 == 0)
            insert_num(arr, &n, fib(num_of_multiple_of_three++), ++i);
    }
    return n;
}

int insert_num(int arr[], int *pn, int a, int k)
{
    if (k > *pn)
        return INDEX_OUT_OF_BOUNDS;
    for (int i = ++(*pn); i > k; i--)
        arr[i] = arr[i - 1];
    arr[k] = a;
    return OK;
}

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return (fib(n - 1) + fib(n - 2));
}