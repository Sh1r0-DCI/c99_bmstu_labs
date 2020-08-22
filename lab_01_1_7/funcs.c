#include <stdio.h>
#include <math.h>
#include "funcs.h"

double function_f(double x)
{
    return sin(x);
}

double function_s(double x, double eps)
{
    double ans = x, el = x;
    for (int i = 3; fabs(el) > eps; i += 2)
    {
        el *= (-1) * x * x / (i * (i - 1));
        ans += el;
    }
    return ans;
}

int check_input(int rc, double x, double eps)
{
    if (rc != 2)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    if (eps <= 0 || eps >= 1)
    {
        printf("Incorrect input of eps.");
        return EPS_INPUT_ERROR;
    }
    return OK;
}
