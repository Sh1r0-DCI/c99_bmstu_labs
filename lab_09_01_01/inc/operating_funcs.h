#ifndef __OPERATING_FUNCS_H__

#define __OPERATING_FUNCS_H__

#include "strucs.h"

int alloc_struc_array(FILE *f, film_info **p_films, int *p_num_of_films);
void free_array(film_info *films, int num_of_films);
int insert_struc(film_info *films, int num_of_films, char *field, 
                                    char *title, char *name, int year);
int field_bin_search(film_info *films, int n, char *field, char *key);

#endif