#include "funcs.h"
#include "error_code.h"

/*void row_sum_matrix_bubble_sort(int matr[][M], int n, int m)
{
    for (int k = 0; k < n; k++)
    {
        int sum1 = 0, sum2 = 0;
        sum1 = row_el_sum(matr, 0, m);
        for (int i = 1; i < n - k; i++)
        {
            sum2 = row_el_sum(matr, i, m);
            if (sum1 > sum2)
                change_rows(matr[i - 1], matr[i], m);
            else
                sum1 = sum2;
        }
    }
}*/

void row_sum_matrix_selection_sort(int matr[][M], int n, int m)
{
    for (int k = 0; k < n; k++)
    {
        int min_sum = row_el_sum(matr, k, m), min_id = k;
        for (int i = k + 1; i < n; i++)
        {
            int cur_sum = row_el_sum(matr, i, m);
            if (cur_sum < min_sum)
            {
                min_sum = cur_sum;
				min_id = i;
            }
        }
        if (min_id != k)
            change_rows(matr[k], matr[min_id], m);
    }
}

int row_el_sum(int matr[][M], int i, int m)
{
    int sum = 0;
    for (int j = 0; j < m; j++)
        sum += matr[i][j];
    return sum;
}

void change_rows(int *p_row1, int *p_row2, int m)
{
    int temp;
    for (int j = 0; j < m; j++)
    {
        temp = *(p_row1 + j);
        *(p_row1 + j) = *(p_row2 + j);
        *(p_row2 + j) = temp;
    }
}