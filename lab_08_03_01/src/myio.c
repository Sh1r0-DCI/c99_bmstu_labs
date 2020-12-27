#include <stdio.h>
#include <stdlib.h>

#include "../inc/strucs.h"
#include "../inc/error_codes.h"

int read_sizes(int *row, int *col)
{
    printf("input matrix sizes:\n");

    if (scanf("%d %d", row, col) != 2)
    {
        return INPUT_ERROR;
    }

    if (*row <= 0 || *col <= 0)
    {
        return INPUT_ERROR;
    }

    return OK;
}

int read_matrix(matrix_t **matr, int row, int col)
{
    printf("input matrix:\n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(scanf("%d", &((*matr)->data[i][j])) != 1)
            {
                return INPUT_ERROR;
            }
        }
    }

    return OK;
}

void matrix_print(matrix_t *matr)
{
    if (0 != matr && 0 != matr->data)
    {
        for (size_t i = 0; i < matr->rows; i++)
        {
            for (size_t j = 0; j < matr->cols; j++)
            {
                printf("%3d ", matr->data[i][j]);
            }

            printf("\n");
        }
    }
}