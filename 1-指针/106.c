// date:17.4.5
// author: linyang <942510346@qq.com>


#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x, *p;

	p = &x;
	*p = 0;
	printf("x : %d\n", x);
	printf("*p : %d\n", *p);
	*p += 1;
	printf("x : %d\n", x);
	(*p)++;
	printf("x : %d\n", x);

	return 0;
}