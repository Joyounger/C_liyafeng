#include <stdio.h>

int x = 0;

int modifyvalue()
{
	return (x += 10);
}

int changevalue(int x)
{
	return (x += 1);
}


int main(int argc, char const *argv[])
{
	int x = 10;

	x++;
	changevalue(x);
	x++;
	modifyvalue();
	printf("first output: %d\n", x);
	x++;
	x = changevalue(x);
	printf("second output:%d\n", x);
	x = modifyvalue();
	printf("third output: %d\n", x);

	return 0;
}