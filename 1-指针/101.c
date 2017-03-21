#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *p1 = "china";
	char *p2, *p3;
	p2 = (char*)malloc(20);
	memset(p2, 0, 20);
	while(*p2++ = *p1++) ;
	
	printf("%s\n", p2);
		
		
	return 0;
	
}