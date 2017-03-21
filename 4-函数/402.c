#include <stdio.h>
#include <string.h>

unsigned int hexToDec(const char *hex, int n)
{
	unsigned int dec = 0;
	int i = n - 1;

	if (hex == NULL || n <= 0 || n > 8)
	{
		printf("输入参数无效\n");
		return -1;
	}
	while (i >= 0)
	{
		if((hex[i] >= '0') && (hex[i] <= '9'))
		{
			dec += (hex[i] - '0') << (4*(n - i - 1));
		}
		else if((hex[i] >= 'A') && (hex[i] <= 'F'))
		{
			dec += (hex[i] - 'A' + 10) << (4 * (n - i - 1));
		}
		else if((hex[i] >= 'a') && (hex[i] <= 'f'))
			dec += (hex[i] - 'a' + 10) << (4 * (n - i - 1));
		else
		{
			printf("输入参数无效\n");
			return -1;
		}
		i--;
	}
		
	return dec;
}

int main()
{
	char h[9] = {0};
	unsigned int v = 0;
	
	scanf("%s", h);
	v = hexToDec(h, strlen(h));
	printf("0x%s = %u\n", h, v);
	
	return 0;	
	
}

