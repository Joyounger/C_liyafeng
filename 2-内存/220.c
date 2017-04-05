// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>

typedef union FloatData
{
	float f;
	unsigned char h[4];	
}FLOAT;

int main(void)
{
	float tmp;
	FLOAT t;
	
	printf("please input a float:\n");
	scanf("%f", &tmp);
	t.f = tmp;
	printf("%f in memory:0x%2.2x 0x%2.2x 0x%2.2x 0x%2.2x\n", t.f, t.h[0], t.h[1], t.h[2], t.h[3]);
	
	return 0;	
}


/*
kolya@asus ~/src/C_liyafeng/2-内存 $ ./220
please input a float:
-21.375
-21.375000 in memory:0x00 0x00 0xab 0xc1
*/
