#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	int x;
	x=1;   printf("%d %d\n",x,x++);
	x=1;   printf("%d %d\n",x++,x);
	x=1;   printf("%d %d %d\n",x,x++,x);
	x=1;   printf("%d %d %d %d\n",x,++x,x++,x);
	
}


/* ��������
����a++�Ľ��������ebpѰַ����ջ�ռ�����¼�м����ģ�������printfѹջ��ʱ���ٴ�ջ�а��м���ȡ������������++a�Ľ������ֱ��ѹ�Ĵ����������Ĵ������������е����������� ����Դ��http://www.zzzj.com/html/20090609/71613.html��

 # ./1-1_printfѹջ˳��
2 1
1 2
2 1 2
3 3 1 3 */
