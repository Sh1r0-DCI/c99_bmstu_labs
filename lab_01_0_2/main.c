#include <stdio.h>
#include <math.h>

int main(void)
{
	setbuf(stdout, NULL);
	float a, b, h, side_edge, perimetr;
	printf("Input trapezoid bases a, b and height h: ");
	scanf("%f %f %f", &a, &b, &h);
	side_edge = sqrt(pow((a - b) / 2, 2) + pow(h, 2));
	perimetr = side_edge * 2 + a + b;
	printf("%.5f", perimetr);
	return 0;
}