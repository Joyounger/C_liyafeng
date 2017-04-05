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


/*
kolya@asus ~/src/C_liyafeng/1-指针 $ gcc 104.c -o 104
104.c: In function ‘main’:
104.c:9:7: error: assignment of read-only variable ‘p’
     p = &a;
       ^
104.c:12:9: error: assignment of read-only location ‘*p1’
     *p1 =a;
         ^
*/

