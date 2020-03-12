#include <stdio.h>
#include <math.h>

int angle_check(double max, double min1, double min2)
{
	if (fabs(max - min1 - min2) < 0.0001)
	{
		return -1;
	}
	if (pow(max, 2) < pow(min1, 2) + pow(min2, 2))
	{
		return 0;
	}
	else if (fabs(pow(max, 2) - pow(min1, 2) - pow(min2, 2)) < 0.0001)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

int type_of_triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double l1, l2, l3;
	l1 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	l2 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
	l3 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	if (l1 >= l2)
	{
		if (l1 >= l3)
		{
			return angle_check(l1, l2, l3);
		}
		else
		{
			return angle_check(l3, l1, l2);
		}
	}
	else
	{
		if (l2 >= l3)
		{
			return angle_check(l2, l1, l3);
		}
		else
		{
			return angle_check(l3, l1, l2);
		}
	}
}

int main(void)
{
	setbuf(stdout, NULL);
	int rc, ans;
	double x1, y1, x2, y2, x3, y3;
	printf("Input coordinates of the triangle: ");
	rc = scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
	if (rc != 6)
	{
		printf("Input error.");
		return 1;
	}
	ans = type_of_triangle(x1, y1, x2, y2, x3, y3);
	if (ans == -1)
	{
		printf("Incorrect coordinates for triangle.");
		return 2;
	}
	printf("%d", ans);
	return 0;
}