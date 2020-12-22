#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/funcs.h"
#include "../inc/error_codes.h"


int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pe_src <= pb_src || pb_src == NULL || pe_src == NULL)
    {
        return FILTRATION_FAILURE;
    }

    int *p_element = (int *)pe_src;
    int n_dst = 0;

    (*pb_dst) = 0;
    (*pe_dst) = 0;

    for (int *i_p = (int *)pe_src - 1; i_p >= pb_src; i_p--)
    {
        printf("we got element %d\n", *i_p);
        if (*i_p < 0)
        {
            p_element = i_p;
        }

        if (i_p == pb_src && *i_p < 0)
        {
            return FILTRATION_FAILURE;
        }
    }

    for (int *i_p = (int *) pb_src; i_p < p_element; ++i_p)
    {
        n_dst++;
    }

    *pb_dst = calloc(n_dst, sizeof(int));

    if (*pb_dst == NULL)
    {
        return FILTRATION_FAILURE;
    }

    *pe_dst = *pb_dst + n_dst;

    for (int *i_p_dst = *pb_dst, *i_p_src = (int *) pb_src; i_p_dst < *pe_dst; i_p_dst++, i_p_src++)
    {
        *i_p_dst = *i_p_src;
    }
    
    return OK;
}

int fget_numbers(FILE *f, int *numbers)
{
    int number, temp = 0;
    *numbers = 0;

    while (!feof(f) && (number = fscanf(f, "%d", &temp)) != EOF)
    {
        (*numbers)++;

        if (number != 1)
        {
            return INPUT_ERROR;
        }
    }

    if (number == EOF)
    {
        return INPUT_ERROR;
    }

    return OK;
}