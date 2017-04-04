// date:17.4.4
// author: linyang <942510346@qq.com>
// 510 select()函数用法

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, char* argv[])
{
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "192.168.220.128", &servaddr.sin_addr);
    servaddr.sin_port = htons(SERV_PORT);
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        write(sockfd, buf, strlen(buf));
        n = read(sockfd, buf, strlen(buf));
        if (n == 0)
        {
            printf("the other side has been closed.\n");
        } else {
            printf("received: %s\n", buf);
        }
    }
    close(sockfd);
    return 0;
}