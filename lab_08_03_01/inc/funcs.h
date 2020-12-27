#ifndef _FUNCS_H_

#define _FUNCS_H_

#include "strucs.h"


void*matrix_dup(matrix_t *src);
void matrix_copy(matrix_t *dst, matrix_t *src);
void matrix_destroy(matrix_t **matr);
void *matrix_mul(struct Matrix *a, struct Matrix *b);
matrix_t *matrix_transform_3(matrix_t *a, matrix_t *b, int p, int y);
void matrix_transform_2(struct Matrix *a, size_t grow);
void find_max (matrix_t *matr, int *row, int *col);
void matrix_delete_row(matrix_t *m, size_t row);
int matrix_alloc(matrix_t **m, int rows, int cols);
void matrix_transform_1(matrix_t *a);


#endif