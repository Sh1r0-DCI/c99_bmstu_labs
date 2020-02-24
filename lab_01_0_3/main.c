#include <stdio.h>
#include <math.h>

int main(void)
{
	setbuf(stdout, NULL);
	float h, t, m, weight, ind;
	printf("Input height h, chest length t, weight m: ");
	scanf("%f %f %f", &h, &t, &m);
	weight = h * t / 240;
	ind = m / pow(h / 100, 2);
	printf("%.5f %.5f", weight, ind);
	return 0;
}