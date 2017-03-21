#include <stdio.h>

int main()
{
    char str[10];

    fgets(str, sizeof(str), stdin);
    printf("print fgets() string:\n");
    printf("%s\n", str);

    return 0;

}