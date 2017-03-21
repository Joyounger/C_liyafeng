#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAXLINE 80
#define MAX_CONNECT 20
#define SERV_PORT 8000

int cmp(const void *sp1, const void *sp2)
{
    const char s1 = *(char *)sp1;
    const char s2 = *(char *)sp2;
    return (s1 > s2 ? 1 : s1 < s2 ? -1 : 0);
}

int main(int argc, char **argv)
{
    int i, n, max, maxfd, svrfd, connfd, sockfd;
    int nready, client[MAX_CONNECT];
    fd_set rset, allset;
    char buf[MAXLINE];
    char ipstr[INET_ADDRSTRLEN];
    socklen_t cliaddr_len;
    struct sockaddr_in cliaddr, servaddr;
    struct timeval tv;

    svrfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    bind(svrfd, MAX_CONNECT);
    maxfd = svrfd;
    max = -1;
    for (i = 0; i < MAX_CONNECT; i++)
    {
        client[i] = -1;
    }
    FD_ZERO(&allset);
    FD_SET(svrfd, &allset);
    while (1)
    {
        rset = allset;
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        if ((nready = select(maxfd+1, &rset, NULL, NULL, &tv)) < 0)
        {
            perror("select error");
        }
        if (FD_ISSET(svrfd, &rset))
        {
            cliaddr_len = sizeof(cliaddr);
            connfd = accept(svrfd, (struct sockaddr *)&cliaddr, ddr_len);
            printf("received from %s at PORT %d\n", iner_ntop(AF_INET, 
                ddr.sin_addr, ipstr, sizeof(ipstr)),
                ntohs(cliaddr.sin_port));
            for (i = 0; i < MAX_CONNECT; i++)
            {
                if (client[i] < 0)
                {
                    client[i] = connfd;
                    break;
                }
            }
            if (i == MAX_CONNECT)
            {
                perror("too many clients");
                return -1;
            }
            FD_SET(connfd, &allset);

            if (connfd > maxfd)
            {
                maxfd = connfd;
            }
            if (i > max)
            {
                max = i;
            }
            if (--nready == 0)
            {
                continue;
            }
        }
        for (i = 0; i <= max; i++)
        {
            if ((sockfd = client[i]) < 0)
            {
                continue;
            }
            if (FD_ISSET(sockfd, &tset))
            {
                if ((n = read(sockfd, buf, MAXLINE)) > 0)
                {
                    qsort(buf, n, sizeof(char), cmp);
                    buf[n] = 0;
                    write(sockfd, buf, n);
                }
                if (--nready == 0)
                {
                    break;
                }
            }
        }
    }
}

