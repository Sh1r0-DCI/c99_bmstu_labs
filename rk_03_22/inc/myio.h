#ifndef _MYIO_H_

#define _MYIO_H_

int fread_matrix(FILE *f, int **matrix, int n, int m);
int fread_size(FILE *f, int *n, int *m);
void print_matrix_to_file(FILE *f_out, int **matr, int n, int m);

#endif