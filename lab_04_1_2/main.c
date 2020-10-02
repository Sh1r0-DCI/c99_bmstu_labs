#include <stdio.h>
#include "constants.h"
#include "in_out.h"
#include "funcs.h"

int main(void)
{
    setbuf(stdout, NULL);
    int error_code;
    int n/*кол-во символов в строке*/, k/*кол-во слов*/, m/*кол-во символов в слове*/;
    char s[STR_LEN + 1];
    char words_arr[STR_LEN + 1][WRD_LEN + 1];
    if ((error_code = string_input(s, &n)) == OK)
    {
        if ((error_code = string_to_array(s, n, words_arr, &k, &m)) == OK) 
        {
            string_array_selection_sort(words_arr, k, m);
            words_output(words_arr, k, m);
        }
    }
    return error_code;
}