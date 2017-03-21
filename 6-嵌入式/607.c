#include <stdio.h>

#define test(n) printf("test("#n") = %d\n", val##n)

int main()
{
	int val3 = 10;
	int val8 = 23;
	
	test(3);
	test(8);
	
	return 0;
}