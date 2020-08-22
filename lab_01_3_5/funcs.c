#include <stdio.h>
#include "funcs.h"

int check_input(int rc, int a, int b)
{
    if (rc != 2)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    if (a <= 0 || b <= 0)
    {
        printf("Input error. a and b should be natural.");
        return WRONG_INPUT_OF_NUMBER;
    }
    return OK;
}

int nod_rec(int a, int b)
{
    if (a == 0)
        return b;
    return nod_rec(b % a, a);
}