// date:17.4.5
// author: linyang <942510346@qq.com>
// 文件操作

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 80
#define FILE_NAME "test.in"

int main()
{
	char buf[MAX_LINE_LEN];
	FILE *fp;
	char *searchStr = "Lady GaGa";
	int lineID = 0;
	
	fp = fopen(FILE_NAME, "r");
	if(fp == NULL)
	{
		printf("open error\n");
		return 0;
	}
	while(feof(fp) == 0)
	{
		if(!fgets(buf, MAX_LINE_LEN, fp))
			return 0;
		++lineID;
		if(strstr(buf, searchStr))
		{
			printf("Line %d: %s\n", lineID, buf);
		}
	}
	
	if(fp != NULL)
	{
		fclose(fp);
	}
	return 0;
}


/*
Line 3: [05] 07| Lady GaGa, Alejandro
*/