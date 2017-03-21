#include <stdio.h>

int max(int n, ...)
{
    char *paras;
    int max = 0;
    int temp = 0;
    int i = 0;


    paras = (char*)&n + sizeof(n);
    while (n-- > 0)
    {
        //temp = va_arg(paras, int);
        temp = *(int *)(paras + (i++) * sizeof(n));
        max = (max > temp) ? max : temp;
    }

    paras = NULL;
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
