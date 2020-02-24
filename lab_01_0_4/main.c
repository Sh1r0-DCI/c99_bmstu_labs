#include <stdio.h>
#include <math.h>

int main(void)
{
	setbuf(stdout, NULL);
	int s, num_of_bottles, all_bottles = 0;
	printf("Input amount of money s: ");
	scanf("%d", &s);
	while (s >= 45)
	{
		num_of_bottles = s / 45;
		s %= 45;
		s += num_of_bottles * 20;
		all_bottles += num_of_bottles;
	}
	printf("%d", all_bottles);
	return 0;
}