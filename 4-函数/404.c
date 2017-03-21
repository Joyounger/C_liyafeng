#include <stdio.h>

int substrCount(const char *str, char *substr)
{
	const char *s1;
	char *s2;
	int count = 0;
	
	if(str == NULL || substr == NULL)
	{
		printf("参数无效\n");
		return -1;
	}
	while(*str != '\0')
	{
		s1 = str;
		s2 = substr;
		while((*s2 == *s1) != '\0')
		{
			s2++;
			s1++;
		}
		if(*s2 == '\0')
			count++;
		str++;
	}
	return count;
}


