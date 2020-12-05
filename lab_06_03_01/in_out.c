#include <stdio.h>
#include <math.h>
#include "constants.h"
#include "error_codes.h"
#include "strucs.h"

int array_of_strucs_input(FILE *f, prod_info *products, int *pnum_of_products)
{
    if (f == NULL)
        return UNEXISTING_FILE;


    int rc = fscanf(f, "%d", pnum_of_products);


    if (rc != 1)
        return INPUT_ERROR; 

    if (*pnum_of_products < 0 || *pnum_of_products > MAX_NUM_OF_PRODS || *pnum_of_products > 15)
        return INCORRECT_NUM_OF_PRODS;


    int i;
    for (i = 0; i < *pnum_of_products && !feof(f); i++)
    {
        if ((rc = fscanf(f, "%25s%d", products[i].name, &products[i].price)) != 2)
            return INPUT_ERROR;

        if (i != (*pnum_of_products) - 1 && feof(f))
            return INCORRECT_NUM_OF_PRODS;

        if (products[i].price <= 0)
            return INCORRECT_PRODUCT_PRICE;
    }

    if (i != *pnum_of_products || !feof(f))
        return INCORRECT_NUM_OF_PRODS;

        
    return OK;
}

void output_of_required_products(prod_info *products, int num_of_products, double max_price)
{
    for (int i = 0; i < num_of_products; i++)
    {
        if (max_price - (double) products[i].price > EPS)
            printf("%s\n%d\n", products[i].name, products[i].price);
    }
}