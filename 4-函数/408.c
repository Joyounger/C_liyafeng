// date:17.4.5
// author: linyang <942510346@qq.com>
// 函数调用

#include <stdio.h>

void func1(int n);
void func2(int n);
void func3(int n);

void func1(int n)
{
	printf("this is func %d!\n", n);
	func2(2);
	printf("this is func %d\n", n);
}

void func2(int n)
{
	printf("this is func %d!\n", n);
	func3(3);
	printf("this is func %d\n", n);
}

void func3(int n)
{
	printf("this is func %d!\n", n);
}

int main(int argc, char const *argv[])
{
	func1(1);

	return 0;
}
