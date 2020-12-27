#ifndef _MYIO_H_

#define _MYIO_H_

#include "strucs.h"


int read_sizes(int *row, int *col);
int read_matrix(matrix_t **matr, int row, int col);
void matrix_print(matrix_t *matr);


#endif