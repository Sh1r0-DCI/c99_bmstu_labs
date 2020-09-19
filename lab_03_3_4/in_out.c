#include <stdio.h>
#include "in_out.h"
#include "error_code.h"

int matrix_input(int matr[][M], int *pn)
{
    int rc, m;
    printf("Input n and m(the matrix size).\n");
    rc = scanf("%d %d", pn, &m);
    if (rc != 2)
        return INPUT_ERROR;
    else if (*pn < MIN_N || *pn > N || m < MIN_M || m > M)
        return WRONG_VALUE_OF_M_OR_N;
    else if (*pn != m)
        return THE_MATRIX_IS_NOT_SQUARE;
    printf("Input the matrix\n");
    for (int i = 0; i < *pn; i++)
    {
        for (int j = 0; j < m; j++)
        {
            rc = scanf("%d", &matr[i][j]);
            if (rc != 1)
                return INPUT_ERROR;
        }
    }
    return OK;
}

void matrix_output(int matr[][M], int n)
{
    printf("Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
}