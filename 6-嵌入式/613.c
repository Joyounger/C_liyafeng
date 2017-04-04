#include <stdio.h>

union
{
	struct
	{
		unsigned char c1:3;
		unsigned char c2:3;
		unsigned char c3:2;
	} s;
	unsigned char c;
} u;

int main(int argc, char const *argv[])
{
	u.c = 100;
	printf("%d\n", u.s.c1);
	printf("%d\n", u.s.c2);
	printf("%d\n", u.s.c3);

	return 0;
}