#ifndef _FUNCS_H_

#define _FUNCS_H_
#define OK 0
#define N 10
#define INPUT_ERROR 1
#define IS_PRIME 0
#define NOT_PRIME 1
#define NO_PRIMES_IN_ARRAY -1

int array_input(int arr[], int n);
void array_output(int arr[], int n);
int making_prime_num_array(int arr[], int new_arr[], int n);
int prime_num(int a);

#endif