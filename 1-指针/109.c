// date:17.4.5
// author: linyang <942510346@qq.com>

#include <stdio.h>
#include <string.h>
#include <assert.h>

char *mystrcpy(char *dest, char *src)
{
	char *d = dest; // 输入参数的备份
	char *s = src;
	int count = 0;

	assert(dest);	// 指针的合法性检查
	assert(src);
	if (src == dest) {
		return src;
	}

	count = strlen(src) + 1;
	if (count <= 1) {
		return 0;
	}

	if (dest < src || dest >= (src + count)) {
		while (count--) {
			*d++ = *s++;
		}
	} else {
		d = dest + count;
		s = src + count;
		while (count--) {
			*d-- = *s--;
		}
	}

	return dest;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}