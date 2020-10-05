#include <string.h>
#include "constants.h"

int str_duplicate(char words_arr[][WRD_LEN + 1], char temp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(words_arr[i], temp) == 0)
            return THIS_STR_IS_DUPLICATE;
    }
    return NO_DUPLICATES;
}

int string_to_array(char *s, int n, char words_arr[][WRD_LEN + 1], int *pk, int *pm)
{
    *pk = 0;
    *pm = 0;
    char temp[STR_LEN + 1];
    for (int i = 0, j = 0; i < n; i++)
    {
        if (s[i] != ' ' && s[i] != ',' && s[i] != '.' && s[i] != ';' && s[i] != '!' && s[i] != '?' && s[i] != ':' && s[i] != '-')
        {
            if (j > WRD_LEN)
                return WORD_IS_TOO_LONG;
            temp[j++] = s[i];
            if (i == n - 1)
            {
                if (j > *pm)
                    *pm = j;
                if (str_duplicate(words_arr, temp, (*pk) + 1))
                strncpy(words_arr[*pk], temp, j);
                (*pk)++;
            }
        }
        else if (j != 0)
        {
            if (j > *pm)
                *pm = j;
            if (str_duplicate(words_arr, temp, (*pk) + 1))
            {
                strncpy(words_arr[*pk], temp, j);
                (*pk)++;
            }
            memset(temp, 0, j);
            j = 0;
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
