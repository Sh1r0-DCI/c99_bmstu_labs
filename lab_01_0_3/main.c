#include <stdio.h>
#include <math.h>

#define BRUNHALD_CONSTANT 240
#define CENTIMITERS_IN_METRES 100
#define OK 0

int main(void)
{
	setbuf(stdout, NULL);
	double h, t, m, weight, ind;
	printf("Input height h, chest length t, weight m: ");
	scanf("%lf %lf %lf", &h, &t, &m);
	weight = h * t / BRUNHALD_CONSTANT;
	ind = m / pow(h / CENTIMITERS_IN_METRES, 2);
	printf("Your normal weight and BMI:%.5lf %.5lf", weight, ind);
	return OK;
}