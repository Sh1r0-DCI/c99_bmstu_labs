#include <stdio.h>

#define N 1000
#define OK 0

int form_new_array(int a[], int na[], int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i] == na[j])
					break;
				if (j == n - 1)
					na[k++] = a[i];
			}
		}
	}
	return k;
}

int input_array(int a[])
{
	int element, i = 0;
	while (scanf("%d", &element) == 1)
		a[i++] = element;
	return i;
}

void output_array(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int input_array1(int a[])
{
	int element, i = 0;
	while (scanf("%d", &element) == 1)
	{
		if (element > 0)
		{
			for (int j = 0; j < N; j++)
			{
				if (element == a[j])
					break;
				if (j == N - 1)
				{
					a[i++] = element;
					printf("%d\n", element);
				}
			}
		}
	}
	return i;
}

int main()
{
	int a[N];
	int na[N];
	int n, nn;
	n = input_array(a);
	nn = form_new_array(a, na, n);
	printf("%d", nn);
	return OK;
}