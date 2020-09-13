#ifndef _FUNCS_H_

#define _FUNCS_H_
#define MAX_M 10

void row_lower_element_matrix_bubble_sort(int matr[][MAX_M], int n, int m);
void change_rows(int matr[][MAX_M], int n, int m, int row1, int row2);
int lower_element_in_row(int matr[][MAX_M], int n, int m, int row);

#endif