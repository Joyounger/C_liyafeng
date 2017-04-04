// date:17.4.5
// author: linyang <942510346@qq.com>
// 找出子串的个数

#include <stdio.h>

int substrCount(const char *str, char *substr)
{
	const char *s1;
	char *s2;
	int count = 0;
	
	if(str == NULL || substr == NULL)
	{
		printf("²ÎÊýÎÞÐ§\n");
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

int main(int argc, char const *argv[])
{
	const char *s = "President Obama has announced his support for India's bid for a permanent place on the United Nation Security council. Obama was addressing the Indian parliament.";
	char *sub = "Obama";
	int n = 0;

	n = substrCount(s, sub);
	printf("String: %s\n", s);
	printf("Substring: %s\n", sub);
	printf("Count: %d\n", n);

	return 0;
}


