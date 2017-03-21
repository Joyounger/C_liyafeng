#include <stdio.h>

#define M 10					//迷宫实际的行数
#define N 11					//迷宫实际的列数
#define MAXSIZE 2000	//栈的最大深度
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3
#define DIRECTIONS 4

int maze[M][N] = {		//定义一个迷宫数组，1代表障碍物，0代表顺畅
	0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0,
	0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1,
	0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
	1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0,
	1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0,
	0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1,
	1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0,
	0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0,
	1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0,
	0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0,
};

typedef struct datatype {		//记录迷宫中存放每个成员的数据类型
	int x;				//表示横坐标
	int y;				//表示纵坐标
	int d;				//前行方向
	char dir[6];		//关于方向的描述
} datatype;
typedef struct seqstack		//定义一个栈的结构体
{
	datatype data[MAXSIZE];
	int top;								//栈顶指针
}seqstack;

seqstack seq;			//存放在探索迷宫过程中的路径信息
seqstack *s;			//传递seqstack类型的指针变量
datatype temp;		//保存迷宫的当前位置

//寻找迷宫的一条路径
int mazepath(int maze[][N], datatype move[])
{
	int x = 0, y = 0;				
	int d = -1, i = 0, j = 0;
	
	temp.x = 0;
	temp.y = 0;
	temp.d = -1;
	maze[0][0] =  -1;

	push_stack(s, temp);
	while(!empty_stack(s)) 
	{
		pop_stack(s, &temp);
		x = temp.x;
		y = temp.y;
		d = temp.d + 1;
		while(d < DIRECTIONS)
		{
			switch(d)
			{
				case RIGHT:
					if (y == N - 1)
						d++;
					else
						j = y + move[d].y;
					i = x + move[d].x;
					break;
				case DOWN:
					if (x == M-1)
						d++;
					else
                        i = x + move[d].x;
                    j = y + move[d].y;
                    break;
                case LEFT:
                    if (x == 0)
                        d++;
                    else
                        i = x + move[d].x;
                    j = y + move[d].y;
                    break;
                case UP:
                    if (y == 0)
                        d++;
                    else
                        j = y + move[d].y;
                    i = x + move[d].x;
                    break;
                default:
                    printf("direction error!\n");
                    break;
            }
            if (maze[i][j] == 0)
            {
                temp.x = x;
                temp.y = y;
                temp.d = d;
                maze[x][y] = -1;
                push_stack(s, temp);
                x = i;
                y = j;
                if ((x + 1) == M && (y + 1) == N)
                    return 1;
                else
                    d = 0;
            }
            else
                d++;
        }
    }
    return 0;                     
}

int push_stack(seqstack *s, datatype x)
{
    if (s->top == MAXSIZE - 1)
        return 0;
    else {
        s->top++;
        s->data[s->top] = x;
        return 1;
    }
}

int empty_stack(seqstack *s)
{
    if (s->top == 0)
        return 1;
    else
        return 0;
}

int pop_stack(seqstack *s, datatype *x)
{
    if (empty_stack(s))
        return 0;
    else {
        *x = s->data[s->top];
        s->top--;
        return 1;
    }
}

void print_maze()
{
    int i = 0, j = 0;

    for (i = 0; i < M; i++ )
    {
        if (i == 0)
        {
            printf("    ");
            for (j = 0; j < N; j++)
                printf("  C%d:", j);
            printf("\n");            
        }
        printf("R%d:", i);
        for (j = 0; j < N; j++)
                printf(" %4d", maze[i][j]);
        printf("\n");
    }
}

int main()
{
	int i = 0, j = 0, r = 0;
    datatype move[4] = {  //每次的移动方向
        0, 1, 0, "RIGHT",      
        1, 0, 1, "DOWN",
        0, -1, 2, "LEFT",
        -1, 0, 3, "UP",
    };
     
     s = &seq;
     printf("The maze array:\n");
     print_maze();
     r = mazepath(maze, move);
     if (r == 1)
     {
         printf("the valid path is (step from exit to entry):\n");
         while (!empty_stack(s))
         {
             pop_stack(s, &temp);
             printf(" <%d, %2d>, %s\n", temp.x, temp.y, move[temp.d].dir);
         }
     } else {
        printf("threr is not a valid path!\n");
     }
    
	return 0;
}
