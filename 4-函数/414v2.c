// date:17.4.5
// author: linyang <942510346@qq.com>
// 大小写字母转换


#include <stdio.h>
#include <string.h>

char mytoupper(char c)
{
	if (c >= 'a' && c <= 'z') {
		return (c - 'a' + 'A');
	} else {
		return c;
	}
}

int main(int argc, char const *argv[])
{
	int i = 0;
	char str[] = "THIS is a TEST";

	while(str[i] != '\0') {
		str[i] = mytoupper(str[i]);
		i++;
	}
	printf("%s\n", str);

	return 0;
}