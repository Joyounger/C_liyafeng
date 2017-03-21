#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int cip2uint(char cip[])
{
    unsigned int uip = 0;
    int i,j;
    char *p;

    if (strlen(cip) > 15 || strlen(cip) < 7)
    {
        return 0;
    }
    p = strtok(cip, ".");
    for (uip = i =0; i < 4 && p; ++i)
    {
        if (strlen(p) > 3)
        {
            return 0;
        }
        j = atoi(p);
        if (j < 0x00 || j > 0xFF)
        {
            return 0;
        }
        uip <<= 8;
        uip += j;
        p = strtok(NULL, ".");
    }
    return ((((uip) & 0xff000000) >> 24) |
        (((uip) & 0x00ff0000) >> 8) |
        (((uip) & 0x0000ff00) << 8) |
        (((uip) & 0x00ff00ff) << 24));
}

int main()
{
    char ip[15];
    unsigned int uip = 0;
    scanf("%s", ip);
    uip = cip2uint(ip);
    printf("%.8X\n", uip);
    return 0;
}

