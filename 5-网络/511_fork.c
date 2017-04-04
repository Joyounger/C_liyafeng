// date:17.4.4
// author: linyang <942510346@qq.com>
// 511 fork()与pthread_create()

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd[2];
    int val = 0;
    int r;

    if ((r = socketpair(AF_UNIX, SOCK_STREAM, 0, fd)) < 0)
    {
        perror("socketpair()");
        exit(1);
    }
    switch(fork()) {
        case -1:
            perror("fork()");
        break;
        case 0:
            {
                int temp;
                close(fd[0]);
                while (1)
                {
                    read(fd[1], &temp, sizeof(temp));
                    --val;
                    printf("Child val = %d\n", val);
                    write(fd[1], &temp, sizeof(temp));
                }
                break;
            }
        default:
            close(fd[1]);
            while (1)
            {
                sleep(1);
                ++val;
                printf("parent sending val = %d\n", val);
                write(fd[0], &val, sizeof(val));
                read(fd[0], &val, sizeof(val));
                printf("parent received val = %d\n", val);
            }
            break;
    }
    return 0;
}


/*
kolya@asus ~/src/C_liyafeng/5-网络 $ ./511_fork
parent sending val = 1
Child val = -1
parent received val = 1
parent sending val = 2
Child val = -2
parent received val = 2
parent sending val = 3
Child val = -3
parent received val = 3
parent sending val = 4
Child val = -4
parent received val = 4
parent sending val = 5
Child val = -5
parent received val = 5
parent sending val = 6
Child val = -6
parent received val = 6
parent sending val = 7
Child val = -7
parent received val = 7
parent sending val = 8
Child val = -8
parent received val = 8
parent sending val = 9
Child val = -9
parent received val = 9
parent sending val = 10
Child val = -10
parent received val = 10
*/