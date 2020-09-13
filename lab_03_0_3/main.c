#include <stdio.h>
#include "error_code.h"
#include "funcs.h"
#include "in_out.h"

int main(void)
{
    setbuf(stdout, NULL);
    int matr[N][M];
    int n, m, rc, ci = OK;
    if ((rc = matrix_input(matr, &n, &m)) == INPUT_ERROR)
    {
        ci = INPUT_ERROR;
        printf("Input error.");
    }
    else if (rc == WRONG_VALUE_OF_M_OR_N)
    {
        ci = WRONG_VALUE_OF_M_OR_N;
        printf("Wrong value of n or m.");
    }
    else
    {
        row_sum_matrix_bubble_sort(matr, n, m);
        matrix_output(matr, n, m);
    }
    return ci;
}