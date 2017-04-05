// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>

int main(int argc, char const *argv[])
{
	struct st_t
	{
		int status;
		short* pdata;
		char errstr[32];
	};
	struct st_t st[16];
	char* p = (char *)(st[2].errstr + 32);
	printf("%d\n", (p - (char *)(st)));

	return 0;
}


/*
64位系疏下执行结果：
kolya@asus ~/src/C_liyafeng/2-内存 $ ./203
144
*/