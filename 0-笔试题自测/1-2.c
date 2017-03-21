#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *func()
{
	char *a;
	a = (char*)malloc(5);
	strcpy(a, "ABCDE");
	a = "CDE";
	return a;
}

int main()
{
	printf("%s", func());
	
}
