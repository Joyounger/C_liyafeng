// date:17.4.5
// author: linyang <942510346@qq.com>

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int *ip1, *ip2, ivalue;
	char *cp1, *cp2, cvalue;
	ip1 = (int *)0x500;
	ip2 = (int *)0x518;
	ivalue =  ip2 - ip1;
	cp1 = (char *)0x500;
	cp2 = (char *)0x518;
	cvalue = cp2 - cp1;
	printf("%d, %d\n", ivalue, cvalue);

	return 0;
}


/*
kolya@asus ~/src/C_liyafeng/1-指针 $ ./107
6, 24
*/