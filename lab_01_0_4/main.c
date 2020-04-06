#include <stdio.h>
#include <math.h>

#define EMPTY_BOTTLE_PRICE 20
#define DIF_BETWEEN_FULL_AND_EMPTY 25
#define OK 0

int main(void)
{
	setbuf(stdout, NULL);
	int s, num_of_bottles;
	printf("Input amount of money s: ");
	scanf("%d", &s);
	num_of_bottles = (s - EMPTY_BOTTLE_PRICE) / DIF_BETWEEN_FULL_AND_EMPTY;
	printf("Number of bottles you can buy: %d", num_of_bottles);
	return OK;
}