#include <stdlib.h>

#include "funcs.h"

void matrix_alloc(int ***matr, int n, int m)
{
    *matr = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        (*matr)[i] = calloc(m, sizeof(int));
    }
}

void matrix_destroy(int ***matr, int n)
{
    for (int i = 0; i < n; i++)
    {
        free((*matr)[i]);
    }

    free(*matr);
}

void matrix_transform_1(int **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr[i][j] == 0)
            {
                matr[i][j] = num_of_neighb(matr, n, m, i, j);
            }
        }
    }
}

int num_of_neighb(int **matr, int n, int m, int row, int col)
{
    int counter = 0;

    for (int i = row - 1; i < n && i <= row + 1; i++)
    {
        if (i < 0)
        {
            continue;
        }

        for (int j = 0; j < m && j < col + 1; j++)
        {
            if (j < 0)
            {
                continue;
            }

            if (matr[i][j] == -1)
            {
                counter++;
            }
        }
    }
    
    return counter;
}

void matrix_tranform_2(int ***matr, int *n, int m)
{
    int not_zero = 0;

    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr[i][j] != 0)
            {
                not_zero++;
            }
        }
        
        if (!(not_zero))
        {
            delete_row(matr, n, m, i);
        }
    }
}

void delete_row(int ***matr, int *n, int m, int row)
{
    int **temp_matr = NULL;
    matrix_alloc(&temp_matr, *n - 1, m);

    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == row)
            {
                continue;
            }
            else if (i > row)
            {
                temp_matr[i - 1][j] = (*matr)[i][j];
            }
            else
            {
                temp_matr[i][j] = (*matr)[i][j];
            }
        }
    }

    matrix_destroy(matr, (*n)--);
    matrix_alloc(matr, *n, m);
    matrix_cpy(*matr, temp_matr, *n, m);
    matrix_destroy(&temp_matr, *n);
}

void matrix_cpy(int **dst, int **src, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dst[i][j] = src[i][j];
        }
    }
}