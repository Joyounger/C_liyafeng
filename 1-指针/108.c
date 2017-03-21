#include <stdio.h>

int main()
{
	char *str = "Hello, Beijing";
	
	printf("%s\n", str);
	printf("%10.5s\n", str);
	printf("%-10.5s\n", str);
	
	return 0;
}