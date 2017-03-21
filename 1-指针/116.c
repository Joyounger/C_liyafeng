#include <stdio.h>

#define MAXLEN 50


int data[MAXLEN];	//�洢����׳˺�λ��������

int *calcfact(int N)
{
	int i,j,k,r;	//ѭ����������
	int digit = 1;	//����λ������
	for (i = 1; i < MAXLEN; i++) 	//��ʼ������
	{
		data[i] = 0;
	}
	
	data[0] = 1;
	data[1] = 1;
	
	for (i = 1; i < N+1; i++)
	{
		for(j = 1; j < digit + 1; j++)
		
			data[j] *= i;					//����׳�
			for(j = 1; j < digit + 1; j++)
			{
				if(data[j] > 9)
				{
					for(r = 1; r < digit + 1; r++)
					{
						if(data[digit] > 9)
							digit++;		//�������е�ֵ����10��λ����1			
						data[r + 1] += data[r] / 10;
						data[r] = data[r] % 10;
					}
				}
				
			}
			printf("%d!= ", i);
			for(k = digit; k > 0; k--)
			{
				printf("%d", data[k]);				
			}
			printf("\n");								
	}
	return data;
}

int main()
{
	int N;
	printf("enter a number:");
	scanf("%d", &N);
	calcfact(N);
	return 0;
}