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
		move(x, z);					//��x�����ϵ�һ��Բ���ƶ���z������
	}
	else 
	{
		hanoi(n - 1, x, z, y);		//��n-1��Բ�̴�x�ƶ���y��
		move(x, z);					//��x��ʣ������һ��Բ���ƶ���z��
		hanoi(n - 1, y, x, z);		//��y��n-1��Բ���ƶ���z��
	}
	
}

int main()
{
	int n = 0;
	printf("Input discs n:\n");
	scanf("%d", &n);
	hanoi(n, "No.1", "No.2", "No.3");  //��No.1�����ϵ�n��Բ�̾�No.2�����ƶ���No.3������
	printf("%d discs need move %d times\n", n, count);
	
	return 0;
}