#include <stdlib.h>

#include "../inc/funcs.h"
#include "../inc/strucs.h"
#include "../inc/error_codes.h"


void*matrix_dup(matrix_t *src)
{
    matrix_t *copy;
    matrix_alloc(&copy, src->rows, src->cols);
    matrix_copy(copy, src);
    return copy;
}

void matrix_copy(matrix_t *dst, matrix_t *src)
{
    if (dst->rows >= src->rows && dst->cols >= src->cols)
    {
        for (size_t row = 0; row < src->rows; ++row)
        {
            for (size_t col = 0; col < src->cols; ++col)
            {
                dst->data[row][col] = src->data[row][col];
            }
        }
    }
}

void matrix_destroy(matrix_t **matr)
{
    if (matr != NULL && *matr != NULL)
    {
        if ((*matr)->data == NULL)
        {
            free(*matr);
            return;
        }

        for (size_t i = 0; i < (*matr)->rows; ++i)
        {
            free((*matr)->data[i]);
        }

        free((*matr));
    }
}

void matrix_delete_col(struct Matrix *m, size_t col)
{
    if (0 != m && 0 != m->data && m->cols > col)
    {
        matrix_t *n;
        matrix_alloc(&n, m->rows, m->cols - 1);

        for (size_t row_c = 0; row_c < m->rows; ++row_c)
        {
            for (size_t col_c = 0, col_i = 0; col_c < m->cols; ++col_c)
            {
                if (col == col_c)
                    continue;
                n->data[row_c][col_i] = m->data[row_c][col_c];
                ++col_i;
            }
        }
        matrix_destroy(&m);
        m = calloc(1, sizeof(struct Matrix));
        m->data = n->data;
        m->rows = n->rows;
        m->cols = n->cols;
    }
}

static int max_row(struct Matrix *m, size_t r)
{
    int max = m->data[0][0];

    for (size_t col = 0; col < m->cols; ++col) {
        int v = m->data[r][col];
        if (v > max)
        {
            max = v;
        }
    }
    return max;
}

static int sum_cal(struct Matrix *m, int r, int c)
{
    int sum = 0;

    for (int row = 0; row < r; ++row)
    {
        sum += m->data[row][c];
    }
    return sum / r;
}

void *matrix_mul(matrix_t *a, matrix_t *b)
{
    matrix_t *m;

    if (a->cols == b->cols && a->rows == b->rows)
    {
        matrix_alloc(&m, a->rows, a->cols);

        for (size_t row = 0; row < a->rows; ++row)
        {
            for (size_t col = 0; col < a->cols; ++col)
            {
                for (size_t k = 0; k < a->cols; ++k)
                {
                    int v = m->data[row][col];
                    v += a->data[row][k] * b->data[k][col];
                    m->data[row][col] = v;
                }
            }
        }
    }
    return m;
}

matrix_t *matrix_transform_3(matrix_t *a, matrix_t *b, int p, int y)
{
    matrix_t *aa = matrix_dup(a);
    matrix_t *bb = matrix_dup(b);
    matrix_t *nab;

    --p;

    while (p > 0)
    {
        matrix_t *na = matrix_mul(aa, a);
        matrix_destroy(&aa);
        aa = na;
        --p;
    }

    --y;

    while (y > 0)
    {
        matrix_t *nb = matrix_mul(bb, b);
        matrix_destroy(&bb);
        bb = nb;
        --y;
    }

    nab = matrix_mul(aa, bb);
    matrix_destroy(&aa);
    matrix_destroy(&bb);
    return nab;
}

void matrix_transform_2(matrix_t *a, size_t grow)
{
    if (a->rows >= grow)
    {
        return;
    }

    matrix_t *m;
    matrix_alloc(&m, grow, grow);
    matrix_copy(m, a);

    for (size_t row = a->rows; row < grow; ++row)
    {
        for (size_t col = 0; col < a->cols; ++col)
        {
            int sum = sum_cal(m, row, col);
            m->data[row][col] = sum;
        }
    }

    for (size_t row = 0; row < grow; ++row)
    {
        for (size_t col = a->cols; col < grow; ++col)
        {
            int max = max_row(m, row);
            m->data[row][col] = max;
        }
    }



    matrix_destroy(&a);
    a = calloc(1, sizeof(matrix_t));
    a->data = m->data;
    a->rows = m->rows;
    a->cols = m->cols;
}

void find_max (matrix_t *matr, int *row, int *col)
{
    int max = matr->data[0][0];

    for (size_t i = 0; i < matr->rows; i++)
    {
        for (size_t j = 0; j < matr->cols; j++)
        {
            if (matr->data[i][j] > max)
            {
                max = matr->data[i][j];
                *row = i;
                *col = j;
            }
        }
        
    }
    
}

void matrix_delete_row(matrix_t *m, size_t row)
{
    if (0 != m && 0 != m->data && m->rows > row)
    {
        matrix_t *n;
        matrix_alloc(&n, m->rows - 1, m->cols);

        for (size_t row_c = 0, row_i = 0; row_c < m->rows; ++row_c)
        {
            if (row_c == row)
                continue;
            for (size_t col_c = 0; col_c < m->cols; ++col_c)
            {
                n->data[row_i][col_c] = m->data[row_c][col_c];
            }
            ++row_i;
        }

        matrix_destroy(&m);
        m = calloc(1, sizeof(struct Matrix));
        m->data = n->data;
        m->rows = n->rows;
        m->cols = n->cols;
    }
}

int matrix_alloc(matrix_t **m, int rows, int cols)
{
    *m = malloc(sizeof(matrix_t));
    (*m)->cols = cols;
    (*m)->rows = rows;

    int i;

    (*m)->data = calloc(rows, sizeof(int *));

    for (i = 0; i < rows; ++i)
    {
        (*m)->data[i] = calloc(cols, sizeof(int));

        if ((*m)->data[i] == NULL)
        {
            return ALLOCATION_ERROR;
        }
    }

    return OK;
}

void matrix_transform_1(matrix_t *a)
{
    int c = 0, row = 0, col = 0;

    if (a->rows > a->cols)
    {
        //Удаление строк
        c = a->rows - a->cols;

        while (c != 0)
        {
            find_max(a, &row, &col);
            matrix_delete_row(a, row);
            c--;
        }
    }
    else
    {
        //Удаление столбцов
        c = a->cols - a->rows;
        while (c != 0)
        {
            find_max(a, &row, &col);
            matrix_delete_col(a, col);
            c--;
        }
    }
}