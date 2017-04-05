// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>

int dichotomyFind(int N, int A[], int len)
{
	int low = 0;
	int high = len - 1;
	int middle = 0;

	while(low <= high) {
		middle = (low + high) >> 1;
		if (N == A[middle]) {
			printf("serached %d, index is %d!\n", N, middle);
			return 1;
		} else if (N > A[middle])
			low = middle + 1;
		else
			high = middle - 1;
	}

	return 0;
}


int main(int argc, char const *argv[])
{
	int a[] = {2, 3, 5, 8, 38, 58, 67, 68, 89, 100, 127, 235, 246, 258, 263, 351, 375, 398, 487, 500};
	int l = sizeof(a) / sizeof(a[0]);
	int i = 0, N;

	printf("array countent:\n");
	for (i = 0; i < l; i++) {
		if (i % 8 == 0)  {
			printf("\n");
		}
		printf("%4d\n", a[i]);
	}
	printf("\n Search N is ");
	scanf("%d", &N);
	if (!dichotomyFind(N, a, l))
		printf("Not Found!\n");

	return 0;
}