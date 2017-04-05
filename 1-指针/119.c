// date:17.4.6
// author: linyang <942510346@qq.com>


#include <stdio.h>

union a
{
	char name[5];
	int no;
};

struct b
{
	char name[5];
	int no;	
};


int main(int argc, char const *argv[])
{
	printf("%d\n", sizeof(union a));
	printf("%d\n", sizeof(struct b));

	return 0;
}


/*
kolya@asus ~/src/C_liyafeng/1-指针 $ ./119
8
12
*/