#ifndef _FUNCS_H_

#define _FUNCS_H_
#define OK 0
#define N 20
#define INPUT_ERROR 1
#define NO_MULTIPLES_OF_THREE_IN_ARRAY -1
#define N_IS_OF_WRONG_VALUE 2

int array_input(int arr[], int n);
void array_output(int arr[], int n);
int fib(int n);
void insert_num(int arr[], int n, int a, int k);
int array_change(int arr[], int n);

#endif