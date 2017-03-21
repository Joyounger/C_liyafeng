/*
hexdump函数模仿Linux下的hexdump命令，主要实现以下功能：
1 打印内存地址
2 以16进制打印内存内容
3 打印内存内容对应的ASCII码
*/

#include <stdio.h>
#include <stdlib.h>
void hexdump(unsigned char *p, int c)
{
	printf("\nhexdump begin\n");
	int i;

	if(c < 0)
	{
		c = -c;
	}
	while(1)
	{
		printf("%08x: ", (unsigned int)p);
		for(i = 0; i < 16; i++)
		{
			if(i >= c)
				printf("   ");
			else
				printf("%02x ", p[i]);
		}
		printf("  ");
		for(i = 0; i < 16; i++)
		{
			if(i >= c)
				break;
			if(p[i] < ' ' || p[i] > '~')
				printf(".");
			else
				printf("%c", p[i]);
		}
		printf("\n");
		p += 16;
		c -= 16;
		if(c <= 0)
			break;
	}

	printf("hexdump end\n");
	return;
}

int main()
{
	unsigned char c[] = {'*', 'd', '%', 'x', 'y', 'z'};
	int i[] = {21, 23, 14, 89, 21, 34};
	float f[] = {2.8, 1.9, 8.3, 4.7, 5.9};

	hexdump(c, sizeof(c));
	hexdump((unsigned char *)i, sizeof(i));
	hexdump((unsigned char *)f, sizeof(f));

    system("pause:");
	return 0;
}
