#include <stdio.h>
#include <stdlib.h>

static int a;			//全局静态变量（静态区）
char b[2];				//全局普通变量（静态区）
char *s = "abcdefg";	//常量区

void test()
{
	static int c;     //局部静态变量（静态区）
	int d;			
	
	printf("\nlocal variables:\n");
	printf("c   =0x%.8x\n", c);
	printf("d   =0x%.8x\n", d);
	printf("&c   =%p\n", &c);
	
}

int main()
{
	char *p;
	
	if ((p =(char *)malloc(10)) <= 0)   //堆区
	{
		return 0;
	}
	
	test();
	printf("\nglobal variables:\n");
	printf("a = 0x%.8x\n", a);
	printf("b[0] = 0x%.2x\n", b[0]);
	printf("b[0] = 0x%.2x\n", b[0]);
	
	
}