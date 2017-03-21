#include <stdio.h>

void testMacroDefine()
{
	printf("%s, %d, %s\n",__FILE__, __LINE__, __func__);
	printf("%s, %s\n", __DATE__, __TIME__);
	
}

int main()
{
	testMacroDefine();
	return 0;
	
}