// date:17.4.4
// author: linyang <942510346@qq.com>
// 511 fork()与pthread_create()
// gcc 511_pthread.c -o 511_pthread -lpthread

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
    pthread_exit(NULL);
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

    // close(fd[1]);
    while (1)
    {
        sleep(1);
        ++val;
        if (write(fd[0], &val, sizeof(val)) > 0)
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



/*
kolya@asus ~/src/C_liyafeng/5-网络 $ ./511_pthread
Main: creating thread
Parent sending val = 1
child val = 0
parent received val = 1
Parent sending val = 2
child val = 1
parent received val = 2
Parent sending val = 3
child val = 2
parent received val = 3
Parent sending val = 4
child val = 3
parent received val = 4
Parent sending val = 5
child val = 4
parent received val = 5
Parent sending val = 6
child val = 5
parent received val = 6
Parent sending val = 7
child val = 6
parent received val = 7
Parent sending val = 8
child val = 7
parent received val = 8
Parent sending val = 9
child val = 8
parent received val = 9
Parent sending val = 10
child val = 9
parent received val = 10
Parent sending val = 11
child val = 10
parent received val = 11
Parent sending val = 12
child val = 11
parent received val = 12
Parent sending val = 13
child val = 12
parent received val = 13
^C
*/