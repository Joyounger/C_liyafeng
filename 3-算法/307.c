#include <stdio.h>

#define MAXN 1001
unsigned short amark[MAXN];

unsigned short Dfunc(unsigned short n)
{
    unsigned short a = n, b = 0;

    while (n)
    {
        b = n % 10;
        n = n / 10;
        a += b;
    }

    return a;
}

int main()
{
    unsigned short i = 0, j = 0;

    for (; i < MAXN; i++)
    {
        amark[i] = i;
    }

    for ( i = 1; i < MAXN; i ++)
    {
        j = Dfunc(i);
        if (j < MAXN)
        {
            amark[j] = 0;
        }
        if (amark[i] != 0)
        {
            printf("%4d ", amark[i]);
        }
    }

    return 0;
}