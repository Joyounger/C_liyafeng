#include <stdio.h>

int count = 0;
void move(char *x, char *y)
{
	printf("%5s---------->%5s\n", x, y);
	count++;
}


void hanoi(int n, char *x, char *y, char *z)
{
	if (n == 1)
	{
		move(x, z);					//将x柱子上的一个圆盘移动到z柱子上
	}
	else 
	{
		hanoi(n - 1, x, z, y);		//将n-1个圆盘从x移动到y上
		move(x, z);					//将x上剩余的最大一个圆盘移动到z上
		hanoi(n - 1, y, x, z);		//将y上n-1个圆盘移动到z上
	}
	
}

int main()
{
	int n = 0;
	printf("Input discs n:\n");
	scanf("%d", &n);
	hanoi(n, "No.1", "No.2", "No.3");  //把No.1柱子上的n个圆盘经No.2柱子移动到No.3柱子上
	printf("%d discs need move %d times\n", n, count);
	
	return 0;
}