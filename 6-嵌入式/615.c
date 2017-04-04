#include <stdio.h>

struct DATA
{
	long num;
	char *name;
	short int data;
	char ha;
	short ba[5];
} *p;

int main(int argc, char const *argv[])
{
	p = (struct DATA*)0x10000000;
	printf("%p\n", p + sizeof(*p));
	printf("%p\n", p + 1);
	printf("%p\n", (unsigned long)p + 1);
    printf("%p\n", (int *)p + 1);
    printf("%p\n", (char *)p + 1);

	return 0;
}


/*
615.c: In function ‘main’:
615.c:17:9: warning: format ‘%p’ expects argument of type ‘void *’, but argument 2 has type ‘long unsigned int’ [-Wformat=]
  printf("%p\n", (unsigned long)p + 1);
*/