#include <stdio.h>
#include <stdarg.h>

int max(int n, ...)
{

    va_list paras;
    int max = 0;
    int temp = 0;

    va_start(paras, n);
    while (n -- > 0)
    {
        temp = va_arg(paras, int);
        max = (max > temp) ? max : temp;
    }
    va_end(paras);
    return max;
}

int main()
{
    int m;
    m = max(5, 8, 12, 4, 9, 10);
    printf("m = %d\n", m);
    m = max(3, 8, 9, -1);
    printf("m = %d\n", m);

    return 0;
}