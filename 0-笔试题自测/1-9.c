#include <stdio.h>

int main()
{
	char chr = 127;
	int sum = 100;
	chr += 1;
	sum += chr;
	
	printf("%d\n", sum);
	
	return 0;
}


// output: -28