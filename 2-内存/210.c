#include <stdio.h>
#include <stdlib.h>

static int a;			//ȫ�־�̬��������̬����
char b[2];				//ȫ����ͨ��������̬����
char *s = "abcdefg";	//������

void test()
{
	static int c;     //�ֲ���̬��������̬����
	int d;			
	
	printf("\nlocal variables:\n");
	printf("c   =0x%.8x\n", c);
	printf("d   =0x%.8x\n", d);
	printf("&c   =%p\n", &c);
	
}

int main()
{
	char *p;
	
	if ((p =(char *)malloc(10)) <= 0)   //����
	{
		return 0;
	}
	
	test();
	printf("\nglobal variables:\n");
	printf("a = 0x%.8x\n", a);
	printf("b[0] = 0x%.2x\n", b[0]);
	printf("b[0] = 0x%.2x\n", b[0]);
	
	
}