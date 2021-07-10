#ifndef __MYIO_H__

#define __MYIO_H__

#define _GNU_SOURCE

#include "strucs.h"

int input_strucs_from_file(FILE *f, film_info *films, int num_of_films);
void print_strucs_array(film_info *films, int num_of_films);

#endif