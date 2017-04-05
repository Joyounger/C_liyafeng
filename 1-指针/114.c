// date:17.4.5
// author: linyang <942510346@qq.com>

#include <stdio.h>

void fsizeof(int a[][3])
{
	printf("%d\n", sizeof(a));
}

int main(int argc, char const *argv[])
{
	int a[2][3] = {{101, 102, 103}, {104, 105, 106}};
	fsizeof(a);

	return 0;
}

/*
64位系统上运行结果：
kolya@asus ~/src/C_liyafeng/1-指针 $ ./114
8
*/