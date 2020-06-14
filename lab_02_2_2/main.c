#include <stdio.h>
#include <math.h>

#define OK 0
#define INPUT_ERROR -1
#define N 10
#define NO_ELEMENTS_IN_NEW_ARRAY 1

int first_discharge(int a)
{
	int temp = a;
	while (a > 10)
		a /= 10;
	if (temp == a)
		return -1;
	return a;
}

int rewrite_array(int a[], int na[], int n)
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (first_discharge(a[i]) == a[i] % 10)
		{
			na[j] = a[i];
			j += 1;
		}
	}
	return j;
}

int input_array(int arr[], int n)
{
	int rc;
	printf("input n elements:\n");
	for (int i = 0; i < n; i++) 
	{
		printf("arr[%d] = ", i);
		rc = scanf("%d", &arr[i]);
		if (rc != 1)
			return INPUT_ERROR;
	}
	return OK;
}

void output_array(int arr[], int n)
{
	printf("new array: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

int main(void)
{
	setbuf(stdout, NULL);
	int rc;
	int n, new_n;
	printf("Input n - size of the array: ");
	rc = scanf("%d", &n);
	if (rc != 1)
	{
		printf("Input error.");
		return INPUT_ERROR;
	}
	int arr[N];
	int rcarr = input_array(arr, n);
	if (rcarr == INPUT_ERROR)
	{
		printf("Input error.");
		return INPUT_ERROR;
	}
	int new_arr[N];
	new_n = rewrite_array(arr, new_arr, n);
	if (new_n == 0)
	{
		printf("No new elements.");
		return NO_ELEMENTS_IN_NEW_ARRAY;
	}
	output_array(new_arr, new_n);
	return OK;
}