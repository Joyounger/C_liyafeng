#include <stdio.h>
#include <endian.h>

int mem2int(unsigned char *a)
{
	int b = 0, temp = 0;

#if BYTE_ORDER == LITLT_ENDIAN
	temp = a[3];
	temp <<= 24;
	b |= temp;
	temp = a[2];
	temp <<= 16;
	b |= temp;
	temp = a[1];
	temp <<= 8;
	b |= temp;
	b |= a[0];
	printf("LITLT-ENDIAN\n");
#else
	temp = a[0];
	temp <<= 24;
	b |= temp;
	temp = a[1];
	temp <<= 16;
	b |= temp;
	temp = a[2];
	temp <<= 8;
	b |= temp;
	b |= a[3];
	printf("BIG-ENDIAN\n");
#endif
	return b;
}

int main(int argc, char const *argv[])
{
	unsigned char t[] = {0x12, 0x34, 0xab, 0xcd};
	int val = 0;

	val = mem2int(t);
	printf("val=0x%x\n", val);

	return 0;
}