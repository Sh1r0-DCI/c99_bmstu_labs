#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1
#define WRONG_INPUT_OF_N 2
#define FIB_ZERO 0
#define FIB_FIRST 1

int fib(int n)
{
    int temp0 = FIB_ZERO;
	int temp1 = FIB_FIRST;
	int temp;
    for (int i = 1; i < n; i++)
    {
        temp = temp0 + temp1;
		temp0 = temp1;
		temp1 = temp;
    }
    return temp;
}

int main(void)
{
    setbuf(stdout, NULL);
    int rc, n, ans;
    printf("Input n (the number of the element >=2): ");
    rc = scanf("%d", &n);
    if (rc != 1)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    if (n < 2)
    {
        printf("Input error. n should be >=2.");
        return WRONG_INPUT_OF_N;
    }
    ans = fib(n);
    printf("Your element is: %d", ans);
    return OK;
}