#include <stdio.h>

int main()
{
	short int a = 0x1234;
	unsigned int *c;

	c = (int *)&a;
	printf("c = 0x%.8x\n", *c);
	return 0;	
	
}