#include <stdio.h>

struct DATA
{
	long num;
	char* name;
	short int data;
	char ha;
	short ba[5];
	
} *p;

int main()
{
	p = (struct DATA*)0x10000000;
	printf("%x\n", p + sizeof(*p));
	printf("%x\n", p + 1);
	printf("%x\n", (unsigned long)p + 1);
	printf("%x\n", (int *)p + 1);
	printf("%x\n", (char *)p + 1);
	
	return 0;	
}

/* 输出结果：
64位   
# ./1-8
10000400
10000020
10000001
10000004
10000001 
32位：
kolya@linux3 ~/桌面 $ ./1-8
10000240
10000018
10000001
10000004
10000001 */
