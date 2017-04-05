// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>

int main(int argc, char const *argv[])
{
	char p1[] = "hellp!";
	printf("p1--%d\n", sizeof(p1));

	char *p2 = "hellp!";
	printf("p2--%d\n", sizeof(p2));

	void *p3 = malloc(100);
	printf("p3--%d\n", sizeof(p3));

	char p4[100];
	Func(p4);

	struct student
	{
		char name[10];
		int age;
		int id;
	} *p5;
	printf("p5--%d\n", sizeof(p5));

	return 0;
}

void Func(char p4[100])
{
	printf("p4--%d\n", sizeof(p4));
}



/*
64位系疏下执行结果：
kolya@asus ~/src/C_liyafeng/2-内存 $ ./205
p1--7
p2--8
p3--8
p4--8
p5--8
*/