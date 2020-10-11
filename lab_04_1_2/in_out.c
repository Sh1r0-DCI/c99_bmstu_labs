#include <stdio.h>
#include "in_out.h"
#include "constants.h"
#include "error_code.h"

int string_input(char *s, int *pn)
{
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (i > STR_LEN)
            return STRING_IS_TOO_LONG;
        s[i++] = ch;
    }
    s[i] = '\0';
    *pn = i;
    return OK;
}

void words_output(char words_arr[][WRD_LEN + 1], int k, int m)
{
    printf("Result:");
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%c", words_arr[i][j]);
        printf(" ");
    }
}