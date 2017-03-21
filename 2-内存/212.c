#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[20] = "i'm an engineer";
    char *p;

    p = (char *)malloc(30);
    if (p == NULL)
    {
        return -1;
    }

    memcpy(p , a, 25);

    printf("$s\n", p);
    free(p);

    return 0;
}
