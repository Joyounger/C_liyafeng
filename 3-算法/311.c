// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>

void bublesort(int a[], unsigned int n)
{
	int i = 0, j = 0;
	int temp = 0;

	for (; i < n; i++) {
		for (j = 1; j < n - i; j++) {
			if (a[j] > a[j - 1]) {
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int test[] = {10, 23, 21, 18, 7, 2, 56, 28, 21};
	unsigned int n = sizeof(test) / sizeof(int);
	int i = 0;

	printf("before buble sort:\n");
	while (i < n)
		printf("%3d\n", test[i++]);
	
	bublesort(test, n);
	printf("before buble sort:\n");
	i = 0;
	while (i < n)
		printf("%3d\n", test[i++]);

	return 0;
}

/*
kolya@asus ~/src/C_liyafeng/3-算法 $ ./311
before buble sort:
 10
 23
 21
 18
  7
  2
 56
 28
 21
before buble sort:
 56
 28
 23
 21
 21
 18
 10
  7
  2
*/