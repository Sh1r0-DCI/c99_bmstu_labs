#ifndef _FUNCS_H_

#define _FUNCS_H_
#define MAX_M 10

//void row_sum_matrix_bubble_sort(int matr[][MAX_M], int n, int m);
void row_sum_matrix_selection_sort(int matr[][MAX_M], int n, int m);
int row_el_sum(int matr[][MAX_M], int i, int m);
void change_rows(int *p_row1, int *p_row2, int m);

#endif