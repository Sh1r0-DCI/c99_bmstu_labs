#include <string.h>
#include "constants.h"

int string_to_array(char *s, int n, char words_arr[][WRD_LEN + 1], int *pk, int *pm)
{
    *pk = 0;
    *pm = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        if (s[i] != ' ' && s[i] != ',' && s[i] != '.' && s[i] != ';' && s[i] != '!' && s[i] != '?' && s[i] != ':' && s[i] != '-')
        {
            if (j > WRD_LEN)
                return WORD_IS_TOO_LONG;
            words_arr[*pk][j++] = s[i];
            if (i == n - 1)
            {
                if (j > *pm)
                    *pm = j;
                (*pk)++;
            }
        }
        else if (j != 0)
        {
            if (j > *pm)
                *pm = j;
            j = 0;
            (*pk)++;
        }
    }
    return OK;
}

void change_strings_in_array(char *p_s1, char *p_s2, int m)
{
    char temp;
    for (int j = 0; j < m; j++)
    {
        temp = *(p_s1 + j);
        *(p_s1 + j) = *(p_s2 + j);
        *(p_s2 + j) = temp;
    }
}

void string_array_selection_sort(char words_arr[][WRD_LEN + 1], int k, int m)
{
    for (int l = 0; l < k; l++)
    {
        int min_id = l;
        for (int i = l + 1; i < k; i++)
        {
            if (strcmp(words_arr[i], words_arr[min_id]) < 0)
                min_id = i;
        }
        if (min_id != l)
            change_strings_in_array(words_arr[l], words_arr[min_id], m);
    }
}

