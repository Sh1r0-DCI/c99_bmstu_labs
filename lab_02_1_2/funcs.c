#include <stdio.h>
#include "funcs.h"
#include <stdlib.h>

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

int making_prime_num_array(int arr[], int new_arr[], int n)
{
    int j = 0, num_of_primes = NO_PRIMES_IN_ARRAY;
    for (int i = 0; i < n; i++)
    {
        if (prime_num(arr[i]) == IS_PRIME)
        {
            new_arr[j++] = arr[i];
            num_of_primes += 1;
        }
    }
    return num_of_primes;
}

int prime_num(int a)
{
    int is_prime = IS_PRIME;
    for (int i = 2; i * i <= abs(a); i++)
    {
        if (a % i == 0)
            is_prime = NOT_PRIME;         
    }
    return is_prime;
}