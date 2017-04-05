// date:17.4.6
// author: linyang <942510346@qq.com>


#include <stdio.h>

union w
{
	short int a;
	char b;
} c;

int checkCPUendian(void)
{
	c.a = 1;
	return (c.b == 1);
}

int main(int argc, char const *argv[])
{
	if (checkCPUendian())
		printf("the cpu is Little-endian\n");
	else
		printf("the cpu is Big-endian%s\n");

	return 0;
}


/*
kolya@asus ~/src/C_liyafeng/1-指针 $ ./120
the cpu is Little-endian
*/