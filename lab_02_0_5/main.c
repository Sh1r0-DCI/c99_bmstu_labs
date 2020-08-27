#include <stdio.h>
#include "funcs.h"
#include "error_code.h"

int main()
{
    setbuf(stdout, NULL);
    int ci;
    int a[N];
    int *pa_start = a, *pa_end = a;
    ci = array_input(pa_start, pa_end);
    if (ci == INPUT_ERROR)
        printf("Incorrect input of array.");
    else if (ci == N_IS_OF_WRONG_VALUE)
        printf("n is of wrong value");
    else
	{
		array_output(pa_start, pa_start, pa_end);
		printf("before\n");
        printf("max sum: %d\n", max_sum(pa_start, pa_end));
		array_output(pa_start, pa_start, pa_end);
	}
    return ci;
}