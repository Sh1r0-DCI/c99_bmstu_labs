#include <stdio.h>
#include "funcs.h"

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
    int rc, a, b, ans, ci;
    printf("Input natural a and b: ");
    rc = scanf("%d %d", &a, &b);
    ci = check_input(rc, a, b);
    if (ci == OK)
    {
        ans = nod_rec(a, b);
        printf("Your smallest common factor: %d", ans);
    }
    return ci;
}