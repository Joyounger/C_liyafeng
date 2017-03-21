#include <stdio.h>

int main(int argc, char* argv[])
{
    int i = 0;

    while(argc-- > 0)
        printf(" %s", argv[i++]);

    return 0;

}