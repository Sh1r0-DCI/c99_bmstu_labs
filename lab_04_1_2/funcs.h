#ifndef _FUNCS_H_

#define _FUNCS_H_
#define WL 16

void string_to_array(char *s, int n, char words_arr[][WRD_LEN + 1], int *pk, int *pm);
void zero_out_str(char *s, int n);
void change_strings_in_array(char *p_s1, char *p_s2, int m);
void string_array_selection_sort(char words_arr[][WRD_LEN + 1], int k, int m);

#endif