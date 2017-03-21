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
	scanf("%f", %tmp);
	t.f = tmp;
	printf("%f in memory:0x%2.2x 0x%2.2x 0x%2.2x 0x%2.2x\n" t.f, t.h[0], t.h[1], t.h[2]£¬t.h[3]);
	
	return 0;	
}
