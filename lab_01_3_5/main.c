#include <stdio.h>

#define OK 0
#define INPUT_ERROR 1
#define WRONG_INPUT_OF_NUMBER 2

int nod(int a, int b)
{
	while (a > 0 && b > 0)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

int main(void)
{
    setbuf(stdout, NULL);
    int rc, a, b, ans;
    printf("Input natural a and b: ");
    rc = scanf("%d %d", &a, &b);
    if (rc != 2)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    if (a <= 0 || b <= 0)
    {
        printf("Input error. a and b should be natural.");
        return WRONG_INPUT_OF_NUMBER;
    }
    ans = nod(a, b);
    printf("Your smallest common factor: %d", ans);
    return OK;
}