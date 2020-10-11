#include <string.h>
#include "error_code.h"
#include "constants.h"

int is_char_a_separator(char a)
{
    if (a != ' ' && a != ',' && a != '.' && a != ';' && a != '!' && a != '?' && a != ':' && a != '-')
        return IS_NOT_A_SEPARATOR;
    return IS_A_SEPARATOR;
}

int words_len_check(char *s, int n)
{
    int any_words_in_str = NO_WORDS;
    for (int i = 0, j = 0; i < n; i++)
    {
        if (!(is_char_a_separator(s[i])))
        {
            any_words_in_str = AT_LEAST_ONE_WORD;
            if (j >= WRD_LEN)
                return WORD_IS_TOO_LONG;
            j++;
        }
        else if (j != 0)
            j = 0;
    }
    return any_words_in_str;
}

int str_duplicate(char words_arr[][WRD_LEN + 1], char temp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(words_arr[i], temp) == 0)
            return THIS_STR_IS_DUPLICATE;
    }
    return NO_DUPLICATES;
}