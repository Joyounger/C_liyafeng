// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *a[3][4];
	printf("%d\n", sizeof(a));

	return 0;
}


/*
64位系疏下执行结果：
kolya@asus ~/src/C_liyafeng/2-内存 $ ./201
96
*/