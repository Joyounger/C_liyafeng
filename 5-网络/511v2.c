#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <unistd.h>
int val = 0;

void *childRoutine(void *arg)
{
    int *fd = (int *)arg;
    int temp;

    while (1)
    {
        sleep(1);
        read(fd[1], &temp, sizeof(temp));
        --val;
        printf("child val = %d\n", val);
        write(fd[1], &temp, sizeof(temp));
    }
    ptread_exit(NULL);
}

int main()
{
    int fd[2];
    pthread_t thread;
    if ((socketpair(AF_UNIX, SOCK_STREAM, 0, fd)) < 0)
    {
        perror("socketpair()");
        exit(1);
    }

    printf("Main: creating thread\n");
    if (pthread_create(&thread, NULL, childRoutine, (void *)fd))
    {
        perror("pthread_create()");
        exit(1);
    }

    while (1)
    {
        sleep(1);
        ++val;
        if (write(fd[0], &val;, sizeof(val)) > 0)
        {
            printf("Parent sending val = %d\n", val);
        }
        if (read(fd[0], &val, sizeof(val)) > 0)
        {
            printf("parent received val = %d\n", val);
        }
        
    }
    return 0;
}

