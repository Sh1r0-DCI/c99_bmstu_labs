#include <stdio.h>
#include "in_out.h"
#include "error_code.h"

int matrix_input(int matr[][M], int *pn, int *pm)
{
    int rc;
    printf("Input n and m(the matrix size).\n");
    rc = scanf("%d %d", pn, pm);
    if (rc != 2)
        return INPUT_ERROR;
    else if (*pn < MIN_N || *pn > N || *pm < MIN_M || *pm > M)
        return WRONG_VALUE_OF_M_OR_N;
    printf("Input the matrix\n");
    for (int i = 0; i < *pn; i++)
    {
        for (int j = 0; j < *pm; j++)
        {
            rc = scanf("%d", &matr[i][j]);
            if (rc != 1)
                return INPUT_ERROR;
        }
    }
    return OK;
}

void matrix_output(int matr[][M], int n, int m)
{
    printf("Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
}