// date:17.4.5
// author: linyang <942510346@qq.com>
// sprintf() 与 snprintf()

#include <stdio.h>

int main(int argc, char const *argv[])
{
	char a[20];
	char *p = "Hello,China";
	sprintf(a, "%s", p);
	printf("sprintf a is: %s\n", a);

	snprintf(a, 10, "%s\n", p);
	printf("snprintf a is: %s\n", a);

	return 0;
}