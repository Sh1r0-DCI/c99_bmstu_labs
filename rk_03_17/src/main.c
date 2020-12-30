#include <stdio.h>

#include "error_codes.h"
#include "funcs.h"
#include "myio.h"

int main()
{
    setbuf(stdout, NULL);

    FILE *f = fopen("in.txt", "r");
    FILE *f_out = fopen("out.txt", "w");
    int n, m, rc;
    int **matr = NULL;

    if ((rc = fread_size(f, &n, &m)))
    {
        return rc;
    }

    rewind(f);
    matrix_alloc(&matr, n, m);

    if (matr == NULL)
    {
        return ALLOC_ERROR;
    }

    if ((rc = fread_matrix(f, matr, n, m)))
    {
        matrix_destroy(&matr, n);
        return rc;
    }

    matrix_transform_1(matr, n, m);
    matrix_tranform_2(&matr, &n, m);

    print_matrix_to_file(f_out, matr, n, m);

    matrix_destroy(&matr, n);

    return OK;
}