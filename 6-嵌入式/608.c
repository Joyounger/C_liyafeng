#include <stdio.h>

unsigned numbits(unsigned int n)
{
	int i = 0;

	while (n > 0) {
		n &= (n - 1);
		i++;
	}

	return i;
}

int main(int argc, char const *argv[])
{
	int n;

	scanf("%d", &n);
	printf("%x bits is %d\n", n, numbits(n));

	return 0;
}