// date:17.4.5
// author: linyang <942510346@qq.com>
// sequence of function execution

#include <stdio.h>

int f1()
{
	printf("this is f1()\n");

	return 1;
}

int f2()
{
	printf("this is f2()\n");

	return 2;
}


int main(int argc, char const *argv[])
{
	printf("%d, %d\n", f1(), f2());

	return 0;
}