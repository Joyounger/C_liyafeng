// date:17.4.5
// author: linyang <942510346@qq.com>
// 函数声明与定义

#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *str = "hello,china!";
	tests(str);

	return 0;
}

void tests(const char* s)
{
	printf("%s\n", s);
}