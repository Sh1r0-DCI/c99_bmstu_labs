#include <stdio.h>

int power(int a, int n)
{
	int temp = 1;
	for(int i = 0; i < n; i++)
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
		return 1;
	}
	if (n < 0)
	{
		printf("Input error. n should be non-negative integer.");
		return 2;
	}
	ans = power(a, n);
	printf("%d", ans);
	return 0;
}