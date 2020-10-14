#ifndef _FUNCS_H_

#define _FUNCS_H_
#define WL 16

void my_strncpy(char *s1, char *s2, int n);
int my_strcmp(char *s1, char *s2);
void my_strncpy(char *s1, char *s2, int n);
int my_strlen(char *s);
void string_to_array(char *s, int n, char words_arr[][WRD_LEN + 1], int *pk);
void zero_out_str(char *s, int n);
void string_array_selection_sort(char words_arr[][WRD_LEN + 1], int k);

#endif