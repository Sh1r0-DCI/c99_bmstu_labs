#ifndef __MYIO_H__

#define __MYIO_H__

#include <stdio.h>
#include "strucs.h"

void print_list_to_file(FILE *f, node_t *head);
int read_list_from_file(FILE *f, node_t **head);

#endif