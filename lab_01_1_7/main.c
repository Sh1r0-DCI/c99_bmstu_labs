#include <stdio.h>
#include <math.h>

#define OK 0
#define INPUT_ERROR 1
#define EPS_INPUT_ERROR 2

double function_f(double x)
{
	return sin(x);
}

double function_s(double x, double eps)
{
	double ans = x, el = x;
	for (int i = 3; fabs(el) > eps; i += 2)
	{
		ans += el;
		el *= x * x / (i * (i - 1));
	}
	return ans;
}

int main(void)
{
    setbuf(stdout, NULL);
    int rc;
    double x, eps;
    printf("Input x and eps: ");
    rc = scanf("%lf %lf", &x, &eps);
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
    printf("s(x) = %lf\nf(x) = %lf\n", function_s(x, eps), function_f(x));
    printf("absolute error: %lf\nrelative error: %lf", \
    fabs(function_f(x) - function_s(x, eps)), \
    fabs((function_f(x) - function_s(x, eps)) / function_f(x)));	
    return OK;
}