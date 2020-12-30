#ifndef _FUNCS_H_

#define _FUNCS_H_

void matrix_alloc(int ***matr, int n, int m);
void matrix_destroy(int ***matr, int n);
void matrix_transform_1(int **matr, int n, int m);
int num_of_neighb(int **matr, int n, int m, int row, int col);
void matrix_tranform_2(int ***matr, int *n, int m);
void delete_row(int ***matr, int *n, int m, int row);
void matrix_cpy(int **dst, int **src, int n, int m);

#endif