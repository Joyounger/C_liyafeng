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
                write(fd[0], &val;, sizeof(val));
                read(fd[0], &val, sizeof(val));
                printf("parent received val = %d\n", val);
            }
            break;
    }
    return 0;
}