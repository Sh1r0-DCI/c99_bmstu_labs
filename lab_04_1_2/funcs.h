#ifndef _FUNCS_H_

#define _FUNCS_H_
#define WL 16

int string_to_array(char *s, int n, char words_arr[][WL + 1], int *pk, int *pm);
int str_duplicate(char words_arr[][WL + 1], char temp[], int n);
void string_array_selection_sort(char words_arr[][WL + 1], int k, int m);
void change_strings_in_array(char *p_s1, char *p_s2, int m);

#endif