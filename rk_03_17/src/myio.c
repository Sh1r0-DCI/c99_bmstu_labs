#include <stdio.h>

#include "error_codes.h"

int fread_matrix(FILE *f, int **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(fscanf(f, "%d", &(matrix[i][j])) != 1)
            {
                return INPUT_ERROR;
            }
        }
    }

    return OK;
}

int fread_size(FILE *f, int *n, int *m)
{
    if (f == NULL)
    {
        return EMPTY_FILE;
    }

    int rows = 1, cols = 1;
    char c_temp;

    while (!feof(f))
    {
        c_temp = fgetc(f);

        if (c_temp == ' ')
        {
            cols++;
        }

        if (c_temp == '\n')
        {
            rows++;
        }
    }

    *n = rows;
    *m = cols;

    return OK;
}

void print_matrix_to_file(FILE *f_out, int **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < m; j++)
        {
            fprintf(f_out, "%d ", matr[i][j]);
        }

        fprintf(f_out, "\n");
    }
}