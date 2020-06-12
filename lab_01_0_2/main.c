#include <stdio.h>
#include <math.h>

#define OK 0

int main(void)
{
    setbuf(stdout, NULL);
    double a, b, h, side_edge, perimetr;
    printf("Input trapezoid bases a, b and height h: ");
    scanf("%lf %lf %lf", &a, &b, &h);
    side_edge = sqrt(pow((a - b) / 2, 2) + pow(h, 2));
    perimetr = side_edge * 2 + a + b;
    printf("Perimetr: %.5lf", perimetr);
    return OK;
}