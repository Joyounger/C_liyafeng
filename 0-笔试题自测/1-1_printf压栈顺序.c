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


/* 输出结果：
对于a++的结果，是有ebp寻址函数栈空间来记录中间结果的，在最后给printf压栈的时候，再从栈中把中间结果取出来；而对于++a的结果，则直接压寄存器变量，寄存器经过了所有的自增操作。 （来源：http://www.zzzj.com/html/20090609/71613.html）

 # ./1-1_printf压栈顺序
2 1
1 2
2 1 2
3 3 1 3 */
