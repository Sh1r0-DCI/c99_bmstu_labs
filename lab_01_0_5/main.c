#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1
#define WRONG_INPUT_OF_N 2

int power(int a, int n)
{
	int temp = 1;
	for (int i = 0; i < n; i++)
	{
		temp *= a;
	}
	return temp;
}

int main(void)
{
	setbuf(stdout, NULL);
	int rc, a, n, ans;
	printf("Input integer a and natural (non-negative integer) n: ");
	rc = scanf("%d %d", &a, &n);
	if (rc != 2)
	{
		printf("Input error.");
		return INPUT_ERROR;
	}
	if (n < 1)
	{
		printf("Input error. n should be non-negative integer.");
		return WRONG_INPUT_OF_N;
	}
	ans = power(a, n);
	printf("%d", ans);
	return OK;
}