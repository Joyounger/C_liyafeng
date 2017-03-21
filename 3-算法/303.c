#include <stdio.h>
#include <stdlib.h>

struct Jew {   //用于记录犹太人编号的链表节点
	int number;
	struct Jew* next;  //指向下一个犹太人
};


int main()
{
	struct Jew *jew;	//用于指向链表的起始指针
	struct Jew *r;    	//指向链表当前节点的指针
	int N;				//犹太人个数  	
	int M;				//轮流的间隙
	int i;				//临时变量
	
	printf("请输入M,N\n");
	scanf("%d,%d", &M, &N);
	jew = (struct Jew*)malloc(N * sizeof(struct Jew));
	
	r = jew;				//链表第一个节点
	for(i = 1; i < N; i++)	//链表初始化
	{
		r->number = i;
		r->next = jew + i;
		r = r->next;
	}
	
	r->number = N;
	r->next = jew; //链表最后一个节点指向第一个节点的地址，形成环形链表
	
	printf("自杀顺序:\n");
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