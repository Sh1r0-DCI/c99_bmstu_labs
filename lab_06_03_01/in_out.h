#ifndef _IN_OUT_H_

#define _IN_OUT_H_

#include "strucs.h"

int array_of_strucs_input(FILE *f, prod_info *products, int *pnum_of_products);
void output_of_required_products(prod_info *products, int num_of_products, double max_price);

#endif