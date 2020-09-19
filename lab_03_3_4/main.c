#include <stdio.h>
#include "error_code.h"
#include "funcs.h"
#include "in_out.h"

int main(void)
{
    setbuf(stdout, NULL);
    int matr[N][N];
    int n, rc, ci = OK;
    if ((rc = matrix_input(matr, &n)) == INPUT_ERROR)
    {
        ci = INPUT_ERROR;
        printf("Input error.");
    }
    else if (rc == WRONG_VALUE_OF_N)
    {
        ci = WRONG_VALUE_OF_N;
        printf("Wrong value of n.");
    }
    else
    {
        swapping_mirror_columns(matr, n);
        matrix_output(matr, n);
    }
    return ci;
}