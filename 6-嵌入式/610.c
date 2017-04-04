#include <stdio.h>

int main(int argc, char const *argv[])
{
	char chr = 127;
	int sum = 100;
	chr += 1;
	sum += chr;

	printf("the value of sum is %d\n", sum);
	return 0;
}