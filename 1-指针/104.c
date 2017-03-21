#include <stdio.h>

int main()
{
    int i = 10;
    int a = 3;
    int *const p = &i;
    const int *p1 = &i;
    p = &a;
    *p = a;
    p1 = &a;
    *p1 =a;
    return 0;
}

