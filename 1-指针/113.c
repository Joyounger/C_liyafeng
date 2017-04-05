// date:17.4.5
// author: linyang <942510346@qq.com>

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[2][3][4] = {
			{{101, 102, 103, 104}, {111, 112, 113, 114}, {121, 122, 123, 124}},
			{{201, 202, 203, 204}, {211, 212, 213, 214}, {221, 222, 223, 224}}
		};

	printf("%5d", **(a[0] + 2));
	printf("%4d", sizeof(a));

	return 0;
}


/*
kolya@asus ~/src/C_liyafeng/1-指针 $ ./113
  121  96
*/