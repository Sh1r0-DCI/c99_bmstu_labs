#include <stdio.h>

#include "../inc/error_codes.h"
#include "../inc/strucs.h"
#include "../inc/myio.h"
#include "../inc/funcs.h"

int main(void)
{
    setbuf(stdout, NULL);

    matrix_t *a;
    matrix_t *b;
    int n, m, p, q, ro, gam;
    int rc;


    if ((rc = read_sizes(&n, &m)))
    {
        return rc;
    }

    if((rc = matrix_alloc(&a, n, m)))
    {
        return rc;
    }

    if ((rc = read_matrix(&a, n, m)))
    {
        return rc;
    }


    if ((rc = read_sizes(&p, &q)))
    {
        return rc;
    }

    if((rc = matrix_alloc(&b, p, q)))
    {
        return rc;
    }
    
    if ((rc = read_matrix(&b, p, q)))
    {
        return rc;
    }

    // printf("______________________\n");
    // matrix_print(a);
    // printf("______________________\n");
    // matrix_print(b);
    // printf("______________________\n");
    matrix_transform_1(a);
    matrix_transform_1(b);

    // printf("______________________\n");
    // matrix_print(a);
    // printf("______________________\n");
    // matrix_print(b);
    // printf("______________________\n");
    if (a->rows > b->rows)
    {
        matrix_transform_2(b, a->rows);
    }
    else
    {
        matrix_transform_2(a, b->rows);
    }

    // printf("______________________\n");
    // matrix_print(a);
    // printf("______________________\n");
    // matrix_print(b);
    // printf("______________________\n");
    scanf("%d %d", &ro, &gam);

    matrix_t *result_matrix = matrix_transform_3(a, b, ro, gam);
    matrix_print(result_matrix);

    matrix_destroy(&a);
    matrix_destroy(&b);
    return OK;
}