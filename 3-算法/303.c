#include <stdio.h>
#include <stdlib.h>

struct Jew {   //���ڼ�¼��̫�˱�ŵ�����ڵ�
	int number;
	struct Jew* next;  //ָ����һ����̫��
};


int main()
{
	struct Jew *jew;	//����ָ���������ʼָ��
	struct Jew *r;    	//ָ������ǰ�ڵ��ָ��
	int N;				//��̫�˸���  	
	int M;				//�����ļ�϶
	int i;				//��ʱ����
	
	printf("������M,N\n");
	scanf("%d,%d", &M, &N);
	jew = (struct Jew*)malloc(N * sizeof(struct Jew));
	
	r = jew;				//�����һ���ڵ�
	for(i = 1; i < N; i++)	//�����ʼ��
	{
		r->number = i;
		r->next = jew + i;
		r = r->next;
	}
	
	r->number = N;
	r->next = jew; //�������һ���ڵ�ָ���һ���ڵ�ĵ�ַ���γɻ�������
	
	printf("��ɱ˳��:\n");
	while(r != r->next)
	{
		for(i = 0; i < (M -1); i++)
		{
			r = r->next;
		
		printf("%4d", r->next->number++);
		r->next = r->next->next;
		}
	}
	
	printf("\n When N = %d and M = %d,Josephus, hiding in position %d survives.\n", N, M, r->number);
	free(jew);
	
	return 0;
}