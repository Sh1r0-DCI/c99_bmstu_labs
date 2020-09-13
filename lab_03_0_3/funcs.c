#include "funcs.h"
#include "error_code.h"

void row_sum_matrix_bubble_sort(int matr[][M], int n, int m)
{
    for (int k = 0; k < n; k++)
    {
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < m; j++)
            sum1 += matr[0][j];
        for (int i = 1; i < n - k; i++)
        {
            sum2 = 0;
            for (int j = 0; j < m; j++)
                sum2 += matr[i][j];
            if (sum1 > sum2)
                change_rows(matr, n, m, i - 1, i);
            else
                sum1 = sum2;
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