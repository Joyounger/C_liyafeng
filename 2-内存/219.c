#include <stdio.h>

int formatTime(const char *t, char *out)
{
	int i = 0;
	char *temp = out;
	
	if(NULL == t || strlen(t) != 19 || NULL == out)
	{
		printf("There is an invalid parameter\n");
		return -1;			
	}
	
	for(i = 0; *t !='\0'; i++)
	{
		if(*t == '-' || *t == ',' || *t == ':')
		{
			t++;
			continue;
		}
		else if(*t >= '0' || *t <= '9')
		{
			*temp++ = *t++;				
		}
		else
		{
			printf("There is an invalid parameter\n");	
			return -1;
		}	
	}
	*temp = 'Z';
	printf(" %s\n", out);
	return 0;			
}


int main()
{
	//const char 
	char time[20];
	char Out[16];
	int i;
	scanf("%s", time);
	for(i = 0; i < 16; i++)
	{
		Out[i] = 0;
	}
	
	if (formatTime(time, Out) < 0)
		return -1;
	return 0;
}