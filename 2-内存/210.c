// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>
#include <stdlib.h>

static int a;			//È«¾Ö¾²Ì¬±äÁ¿£¨¾²Ì¬Çø£©
char b[2];				//È«¾ÖÆÕÍ¨±äÁ¿£¨¾²Ì¬Çø£©
char *s = "abcdefg";	//³£Á¿Çø

void test()
{
	static int c;     //¾Ö²¿¾²Ì¬±äÁ¿£¨¾²Ì¬Çø£©
	int d;			
	
	printf("\nlocal variables:\n");
	printf("c   =0x%.8x\n", c);
	printf("d   =0x%.8x\n", d);
	printf("&c   =%p\n", &c);
	printf("&d   =%p\n", &d);
}

int main()
{
	char *p;
	
	if ((p =(char *)malloc(10)) <= 0)   //¶ÑÇø
	{
		return 0;
	}
	
	test();
	printf("\nglobal variables:\n");
	printf("a = 0x%.8x\n", a);
	printf("b[0] = 0x%.2x\n", b[0]);
	printf("b[0] = 0x%.2x\n", b[0]);

	printf("s = %s\n", s);
	printf("&a = %p\n", &a);
	printf("&b[0] = %p\n", &b[0]);
	printf("&b[1] = %p\n", &b[1]);
	printf("s = %p\n", s);
	printf("p = %p\n", p);
	free(p);
	
	return 0;
}



/*kolya@asus ~/src/C_liyafeng/2-内存 $ ./210

local variables:
c   =0x00000000
d   =0x00000000
&c   =0x601068
&d   =0x7fff106ff5c4

global variables:
a = 0x00000000
b[0] = 0x00
b[0] = 0x00
s = abcdefg
&a = 0x601064
&b[0] = 0x60106c
&b[1] = 0x60106d
s = 0x4008a4
p = 0x19df010
*/