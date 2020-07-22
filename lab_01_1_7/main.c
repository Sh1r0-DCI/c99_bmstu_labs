#include <stdio.h>
#include <math.h>
#include "funcs.h"

int main(void)
{
    setbuf(stdout, NULL);
    int rc, ci;
    double x, eps;
    printf("Input x and eps: ");
    rc = scanf("%lf %lf", &x, &eps);
    ci = check_input(rc, x, eps);
    if (ci == OK)
    {
        printf("s(x) = %lf\nf(x) = %lf\n", function_s(x, eps), function_f(x));
        printf("absolute error: %lf\nrelative error: %lf", 
        fabs(function_f(x) - function_s(x, eps)), 
        fabs((function_f(x) - function_s(x, eps)) / function_f(x)));	
    }
    return ci;
}