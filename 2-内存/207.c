// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>

int main()
{
    unsigned char a = -1;
    signed char b = -1;
    char c = -1;
    printf("a = %d, b = %d, c = %d", a, b, c);

    return 0;
}



/*
kolya@asus ~/src/C_liyafeng/2-内存 $ gcc 207.c -o 207
kolya@asus ~/src/C_liyafeng/2-内存 $ ./207
a = 255, b = -1, c = -1


kolya@asus ~/src/C_liyafeng/2-内存 $ gcc 207.c -o 207 -funsigned-char
kolya@asus ~/src/C_liyafeng/2-内存 $ ./207
a = 255, b = -1, c = 255
*/