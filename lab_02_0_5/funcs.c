#include <stdio.h>
#include "funcs.h"
#include "error_code.h"

int array_input(int *pa_start, int *pa_end)
{
	int *pa = pa_start;
    int rc, n;
    printf("Input n - array size: ");
    rc = scanf("%d", &n);
    if (rc != 1)
        return INPUT_ERROR;
    else if (n > MAX_N || n < MIN_N)
    {
        return N_IS_OF_WRONG_VALUE;
    }
    pa_end = pa_start + n;
    printf("Input n elements:\n");
    for (int i = 0; i < pa_end - pa_start; i++, pa++)
    {
        rc = scanf("%d", pa);
        if (rc != 1)
            return INPUT_ERROR;
    }
	array_output(pa_start, pa_start, pa_end);
	printf("\n");
    return OK;
}

void array_output(const int arr[], int *pa_start, int *pa_end)
{
    printf("array:\n");
	printf("%ld\n", pa_end - pa_start);
    for (int i = 0; i < pa_end - pa_start; i++)
        printf("%d ", arr[i]);
}

int max_sum(int *const pa_start, int *const pa_end)
{
	const int *pa = pa_start;
    int sum = *pa_start + *(pa_end - 1);
    for (int i = 0; i <= (pa_end - pa_start - 1) / 2; i++, pa++)
    {
		printf("summing");
        int *pa_backwards = pa_end;
        pa_backwards--;
        for (int j = pa_end - pa_start - 1; j >= (pa_end - pa_start - i - 1); j--)
            pa_backwards--;
        pa_backwards++;
        if (*pa + *pa_backwards > sum)
            sum = *pa + *pa_backwards;
    }
    return sum;
}