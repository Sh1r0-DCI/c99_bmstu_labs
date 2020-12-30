#include <stdio.h>

#include "error_codes.h"

int fread_matrix(FILE *f, int **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(fscanf(f, "%d", &(matr[i][j])) != 1)
            {
                return INPUT_ERROR;
            }
            printf("read [%d][%d] = %d\n", i, j, matr[i][j]);
        }
    }

    return OK;
}

int fread_size(FILE *f, int *n, int *m)
{
    n = 0;
    m = 0;

    if (f == NULL)
    {
        return EMPTY_FILE;
    }

    int rows = 1, cols = 1;
    char c_temp;

    while (!feof(f))
    {
        c_temp = fgetc(f);

        if (c_temp == ' ' && m == 0)
        {
            cols++;
        }

        if (c_temp == '\n')
        {
            rows++;
            *m = cols;
            cols = 1;
        }
    }

    *m = cols;
    *n = rows;

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