#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 64

struct descriptor_url
{
    char protocol[MAX_STR_LEN];
    char hostname[MAX_STR_LEN];
    int port;
};

int parseURL(char *url, struct descriptor_url *d_url)
{
    char *p, *p1;
    int len;

    if (url == NULL || d_url == NULL)
    {
        return -1;
    }
    if ((p = strstr(url, "://")) != NULL)
    {
        if ((len = p -url) >= MAX_STR_LEN)
        {
            return -1;
        }
        strncpy(d_url->protocol, url, len);
        d_url->protocol[len] = '\0';
    } else
        return -1;
    
    p += 3; //skip "://" characters
    p1 = p;
    while ((*p != ':') && (*p != '\0'))
    {
        p++;
    }
    len = p - p1;
    if (len >= MAX_STR_LEN || len == 0)
    {
        return -1;
    }
    strncpy(d_url->hostname, p1, len);
    d_url->hostname[len] = '\0';
    d_url->port = atoi(++p);

    return 0;
};

int main(int argc, char *argv[])
{
    char *srcURL;
    struct descriptor_url dest;

    if (argc < 2)
    {
        printf("Usage: %s url\n", argv[0]);
        return -1;
    }
    srcURL = argv[1];
    if ((parseURL(srcURL, &dest)) == 0)
    {
        printf("Hostname: %s, Protocol: %s, Port: %d\n", dest.hostname, dest.protocol, dest.port);
    } else {
        printf("Invalid URL:%s\n", argv[1]);
    }
    
    return 0;
}