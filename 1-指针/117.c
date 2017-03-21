#include <stdio.h>

#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4

int charRotate(int M, int N)
{
	int dir = RIGHT;
	char a[M][N];
	int x = 0;
	int y = 0;
	int i = 0;
	
	if (M < 1 || N < 1)
	{
		printf("输入参数非法\n");
		return -1;
	}
	
	for(x = 0; x < M; x++)
	{
		for(y = 0; y < N; y++)
		{
			a[x][y] = 0;  //初始化
		}
	}	
	
	x = 0;
	y = 0;
	while(i < M*N)
	{
		a[x][y] = 'A' + i % 26;
		if (i + 1 == M * N)
			break;
		//if reach the edge, turn
turn:
		switch(dir) 
		{
			case RIGHT:
				//test if reach the edge
				if ((y + 1) == N || a[x][y+1] != 0)
				{
					dir = DOWN;
					goto turn;
				}
				//go ahead
				y++; 
				break;
			case DOWN:
				if ((x + 1) == M || a[x+1][y] != 0)
				{
					dir = LEFT;
					goto turn;
				}
				x++; 
				break;
			case LEFT:
				if ((y - 1)== -1 || a[x][y - 1] != 0)
				{
					dir = UP;
					goto turn;
				}				
				y--; 
				break;
			case UP:
				if ((x - 1) == -1 || a[x - 1][y] != 0)
				{
					dir = RIGHT;
					goto turn;
				}				
				x--; 
				break;
			
		}
		i++;
	}
	
	x = 0;
	y = 0;
	for(x = 0; x < M; x++)
	{
		for(y = 0; y < N; y++)
		{
			printf("%4c", a[x][y]);
			
		}
		printf("\n");
	}
	return 0;	
}


int main()
{
	int M,N;
	scanf("%d,%d",&M, &N);
	charRotate(M, N);
	
	return 0;
}