#include <stdio.h>

struct header
{
    char name[10];
    char ver:3,
        hlen:5;
    unsigned int sip;
    unsigned int dip;
    unsigned int tlen;
    char option[8];
    char data[0];
};

int main()
{
    int l;

    l = sizeof(struct header);
    printf("%d\n", l);
    return 0;

}

