#include <stdio.h>
#include <math.h>

int angle_check(float max, float min1, float min2)
{
	if (pow(max, 2) < pow(min1, 2) + pow(min2, 2))
	{
		return 0;
	}
	else if (pow(max, 2) == pow(min1, 2) + pow(min2, 2))
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

int type_of_triangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
	float l1, l2, l3;
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
	int rc;
	float x1, y1, x2, y2, x3, y3;
	printf("Input coordinates of the triangle: ");
	rc = scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);
	if (rc != 6)
	{
		printf("Input error.");
		return 1;
	}
	printf("%d",type_of_triangle(x1, y1, x2, y2, x3, y3));
	return 0;
}