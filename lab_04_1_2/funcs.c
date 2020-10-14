#include "constants.h"
#include "error_code.h"
#include "checks.h"

void zero_out_str(char *s, int n)
{
    for (int i = 0; i < n; i++)
        s[i] = '\0';
}

int my_strcmp(char *s1, char *s2)
{
    char *c1 = s1, *c2 = s2;
    while (*c1 == *c2 && *c1 != '\0' && *c2 != '\0')
    {
        c1++;
        c2++;
    }
    return (*c1) - (*c2);
}

void my_strncpy(char *s1, char *s2, int n)
{
    for(int i = 0; i < n + 1; i++)
        s1[i] = s2[i];
}

int my_strlen(char *s)
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
        count++;
    return count;
}

void string_to_array(char *s, int n, char words_arr[][WRD_LEN + 1], int *pk)
{
    *pk = 0;
    char temp[STR_LEN + 1] = { '\0' };
    for (int i = 0, j = 0; i < n; i++)
    {
        if (!(is_char_a_separator(s[i])))
        {
            temp[j++] = s[i];
            if (i == n - 1)
            {
                if (str_duplicate(words_arr, temp, (*pk) + 1))
                {
                    my_strncpy(words_arr[*pk], temp, j);
                    (*pk)++;
                }
            }
        }
        else if (j != 0)
        {
            if (str_duplicate(words_arr, temp, *pk))
            {
                my_strncpy(words_arr[*pk], temp, j);
                (*pk)++;
            }
            zero_out_str(temp, j);
            j = 0;
        }
    }
}

void string_array_selection_sort(char words_arr[][WRD_LEN + 1], int k)
{
    char temp[STR_LEN + 1];
    for (int l = 0; l < k; l++)
    {
        int min_id = l;
        for (int i = l + 1; i < k; i++)
        {
            if (my_strcmp(words_arr[i], words_arr[min_id]) < 0)
                min_id = i;
        }
        if (min_id != l)
        {
            //change_strings_in_array(words_arr[l], words_arr[min_id]);
            my_strncpy(temp, words_arr[l], my_strlen(words_arr[l]));
            my_strncpy(words_arr[l], words_arr[min_id], my_strlen(words_arr[min_id]));
            my_strncpy(words_arr[min_id], temp, my_strlen(temp));
        }
    }
}
