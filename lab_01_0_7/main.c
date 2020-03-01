#include <stdio.h>
#include <math.h>

double f(double x)
{
	return exp(x);
}

double s(double x, double eps)
{
	double ans = 0, el = 1;
	for (int i = 0; fabs(el) > eps; i++)
	{
		ans += el;
		el = el * x / (i + 1);
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
		return 1;
	}
	if (eps <= 0 || eps >= 1)
	{
		printf("Incorrect input of eps.");
		return 2;
	}
	printf("s(x) = %lf\nf(x) = %lf\n", s(x, eps), f(x));
	printf("absolute error: %lf\nrelative error: %lf", fabs(f(x) - s(x, eps)), \
		fabs((f(x) - s(x, eps)) / f(x)));	
	return 0;
}