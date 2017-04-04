// date:17.4.5
// author: linyang <942510346@qq.com>
// 大小写字母转换

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int i = 0;
	char str[] = "THIS is a TEST";

	while(str[i] != '\0') {
		str[i] = toupper(str[i]);
		i++;
	}
	printf("%s\n", str);

	return 0;
}