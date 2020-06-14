#include <stdio.h>
#include <math.h>

#define OK 0
#define INPUT_ERROR -1
#define NO_NEGATIVE_ELEMENTS 2
#define N 10

int negative_els(int arr[], int n)
{
	int ne = 0;
    for (int i = 0; i < n; i++) 
    {
	    if (arr[i] < 0)
		{
		    ne += 1;
		}
    }
	return ne;
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
	return negative_els(arr, n);
}

void output_array(int arr[], int n)
{
	printf("array: ");
    for (int i = 0; i < n; i++)
	    printf("%d ", arr[i]);
}

double average_negatives(int arr[], int n, int ne)
{
    double an;
	for (int i = 0; i < n; i++)
	    if (arr[i] < 0)
		{
		    an += arr[i];
		}
	an /= ne;
	return an;
}

int main(void)
{
    setbuf(stdout, NULL);
    int rc;
	int n, ne;
    printf("Input n - size of the array: ");
    rc = scanf("%d", &n);
    if (rc != 1)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
	int arr[N];
	ne = input_array(arr, n);
	if (ne == INPUT_ERROR)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
	if (ne == 0)
	{
		printf("No negative elements in array.");
		return NO_NEGATIVE_ELEMENTS;
	}
	printf("average of negatives is %lf\n", average_negatives(arr, n, ne));
	output_array(arr, n);
    return OK;
}