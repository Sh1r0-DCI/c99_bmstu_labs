#include <stdio.h>
#include "in_out.h"
#include "constants.h"
#include "error_codes.h"
#include "strucs.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
        return WRONG_ARGS_INPUT;


    setbuf(stdout, NULL);


    FILE *f = fopen(argv[1], "r");
    int num_of_products, exit_code;
    double max_price;
    prod_info products[MAX_NUM_OF_PRODS];

    if (sscanf(argv[2], "%lf", &max_price) != 1 || max_price <= 0)
        return WRONG_ARGS_INPUT;


    exit_code = array_of_strucs_input(f, products, &num_of_products);
            
    if (!exit_code)
        output_of_required_products(products, num_of_products, max_price);


    return exit_code || (fclose(f) == EOF);
}