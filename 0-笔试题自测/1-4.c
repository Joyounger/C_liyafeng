#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	struct st_t
	{
		int status;
		short *pdata;
		char errstr[32];
	};
	
	struct st_t st[16];
	char *p = (char*) (st[2].errstr + 32);
	printf("%d", (p - (char*)(st)));
	return 0;
	
}
	
/* 	��������
	64λ��144
	32λ��120 */
	
	