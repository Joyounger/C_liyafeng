// date:17.4.4
// author: linyang <linyang@xiaomi.com>
// 508 实现http get

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netdb.h>

#define HTTP_GET "GET / HTTP/1.1\r\nHost: %s\r\nAccept: */*\r\n\r\n"

int main(int argc, char** argv)
{
    int sockfd, n = 0;
    struct hostent *host;
    struct sockaddr_in dest_addr;
    char *dest;
    char httpget[512], *p;
    char buf[1024];
    
    dest = argv[1];
    if (argc < 2)
    {
        printf("usage:%s Hostname / IP address\n", argv[0]);
        exit(1);
    }
    if ((sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        perror("socket error");
        exit(1);
    }
    
    bzero(&dest_addr, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(80);
    if (inet_addr(dest) == INADDR_NONE) 
    {
        if ((host = gethostbyname(dest)) == NULL)
        {
            perror("gethostbyname error");
            exit(1);
        }
        dest = host -> h_name;
        memcpy((char *)&dest_addr.sin_addr, host->h_addr, host->h_length);
    } else {
        dest_addr.sin_addr.s_addr = inet_addr(dest);
    }
    if (connect(sockfd, (const struct sockaddr *)&dest_addr, sizeof(dest_addr)) == -1)
    {
        perror("connect error");
    }

    sprintf(httpget, HTTP_GET, argv[1]);
    if (write(sockfd, httpget, strlen(httpget)) <= 0)
    {
        perror("write error");
    }
        
    n = read(sockfd, buf, 2048);
    p = strstr(buf, "\r\n\r\n");
    *p = '\0';
    printf("n = %d, buf = %s\n", n, buf);

    return 0;
}




/*
kolya@asus ~/src/C_liyafeng/5-网络 $ ./508 www.baidu.com
n = 750, buf = HTTP/1.1 200 OK
Date: Tue, 04 Apr 2017 08:40:34 GMT
Content-Type: text/html
Content-Length: 14613
Last-Modified: Tue, 14 Mar 2017 07:30:00 GMT
Connection: Keep-Alive
Vary: Accept-Encoding
Set-Cookie: BAIDUID=E58A5443A22443C780530C0398BF481B:FG=1; expires=Thu, 31-Dec-37 23:55:55 GMT; max-age=2147483647; path=/; domain=.baidu.com
Set-Cookie: BIDUPSID=E58A5443A22443C780530C0398BF481B; expires=Thu, 31-Dec-37 23:55:55 GMT; max-age=2147483647; path=/; domain=.baidu.com
Set-Cookie: PSTM=1491295234; expires=Thu, 31-Dec-37 23:55:55 GMT; max-age=2147483647; path=/; domain=.baidu.com
P3P: CP=" OTI DSP COR IVA OUR IND COM "
Server: BWS/1.1
X-UA-Compatible: IE=Edge,chrome=1
Pragma: no-cache
Cache-control: no-cache
Accept-Ranges: bytes
*/