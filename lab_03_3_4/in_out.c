#include <stdio.h>
#include "in_out.h"
#include "error_code.h"

int matrix_input(int matr[][M], int *pn)
{
    int rc;
    printf("Input n(the square matrix size).\n");
    rc = scanf("%d", pn);
    if (rc != 1)
        return INPUT_ERROR;
    else if (*pn < MIN_N || *pn > N)
        return WRONG_VALUE_OF_N;
    printf("Input the matrix\n");
    for (int i = 0; i < *pn; i++)
    {
        for (int j = 0; j < *pn; j++)
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