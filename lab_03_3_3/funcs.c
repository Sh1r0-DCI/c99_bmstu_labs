#include "funcs.h"
#include "error_code.h"

void row_lower_element_matrix_bubble_sort(int matr[][M], int n, int m)
{
    for (int k = 0; k < n; k++)
    {
        int l1 = lower_element_in_row(matr, n, m, 0);
        for (int i = 1; i < n - k; i++)
        {
            int l2 = lower_element_in_row(matr, n, m, i);
            if (l1 < l2)
                change_rows(matr, n, m, i - 1, i);
            else
                l1 = l2;
        }
    }
}

void change_rows(int matr[][M], int n, int m, int row1, int row2)
{
    int temp;
    for (int j = 0; j < m; j++)
    {
        temp = matr[row1][j];
        matr[row1][j] = matr[row2][j];
        matr[row2][j] = temp;
    }
}

int lower_element_in_row(int matr[][M], int n, int m, int row)
{
    int lower_el = matr[row][0];
    for (int j = 0; j < m; j++)
    {
        if (matr[row][j] < lower_el)
            lower_el = matr[row][j];
    }
    return lower_el;
}