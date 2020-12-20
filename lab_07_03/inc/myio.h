#ifndef _MYIO_H_

#define _MYIO_H_

#include <stdio.h>


int read_from_file(FILE *f_in, int *in_array_begin, int n, int **in_array_end);
void print_to_file(FILE *f_out, int *out_array_begin, int *out_array_end);


#endif