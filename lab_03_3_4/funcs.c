#include "funcs.h"
#include "error_code.h"

void swapping_mirror_columns(int matr[][M], int n)
{
    for (int i = 0, int j = 0; i < n / 2; i++, j++)
        change_columns(matr, n, j, n - j - 1, i, n - i);
}

void change_columns(int matr[][M], int n, int col1, int col2, int from_i, int to_i)
{
    int temp;
    for (int i = from_i; i < to_i; i++)
    {
        temp = matr[i][col1];
        matr[i][col1] = matr[i][col2];
        matr[i][col2] = temp;
    }
}