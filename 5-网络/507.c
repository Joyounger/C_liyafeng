// date:17.4.4
// author: linyang <linyang@xiaomi.com>
// 507 实现简单ping命令


/*
kolya@asus ~/src/C_liyafeng/5-网络 $ sudo ./507 www.baidu.com
sudo: 无法解析主机：asus
[sudo] kolya 的密码： 
PING www.a.shifen.com(119.75.218.70) 56(84) bytes of data.
64 bytes from 119.75.218.70: icmp_seq = 1 ttl = 56 time = 2.0 ms
64 bytes from 119.75.218.70: icmp_seq = 2 ttl = 56 time = 3.0 ms
64 bytes from 119.75.218.70: icmp_seq = 3 ttl = 56 time = 2.0 ms
64 bytes from 119.75.218.70: icmp_seq = 4 ttl = 56 time = 3.0 ms
64 bytes from 119.75.218.70: icmp_seq = 5 ttl = 56 time = 2.0 ms
64 bytes from 119.75.218.70: icmp_seq = 6 ttl = 56 time = 2.0 ms
64 bytes from 119.75.218.70: icmp_seq = 7 ttl = 56 time = 2.0 ms
64 bytes from 119.75.218.70: icmp_seq = 8 ttl = 56 time = 3.0 ms
64 bytes from 119.75.218.70: icmp_seq = 9 ttl = 56 time = 4.0 ms
64 bytes from 119.75.218.70: icmp_seq = 10 ttl = 56 time = 2.0 ms
64 bytes from 119.75.218.70: icmp_seq = 11 ttl = 56 time = 2.0 ms
64 bytes from 119.75.218.70: icmp_seq = 12 ttl = 56 time = 3.0 ms
64 bytes from 119.75.218.70: icmp_seq = 13 ttl = 56 time = 3.0 ms
64 bytes from 119.75.218.70: icmp_seq = 14 ttl = 56 time = 3.0 ms
64 bytes from 119.75.218.70: icmp_seq = 15 ttl = 56 time = 3.0 ms
64 bytes from 119.75.218.70: icmp_seq = 16 ttl = 56 time = 2.0 ms
64 bytes from 119.75.218.70: icmp_seq = 17 ttl = 56 time = 4.0 ms
^C64 bytes from 119.75.218.70: icmp_seq = 18 ttl = 56 time = 3.0 ms
^C
------Ping www.a.shifen.com statistics----
18 packets transmittted, 18 received, 0% packet loss, time 48 ms
rtt min/avg/max = 2.000/2.667/4.000ms
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>

#define MAX_NO_PACKETS 100 // add by linyang

#define PACKET_SIZE 4 * 1024
#define MAX_WAIT_TIME 5
#define DATA_LEN 56
#define ICMP_HEADER_LEN 8
#define IP_HEADER_LEN 20

int sockfd;
char *dest;
char sendpacket[PACKET_SIZE];
char recvpacket[PACKET_SIZE];
int nsend = 0, nreceived = 0;
double temp_rtt[MAX_NO_PACKETS];
double all_time = 0;
struct sockaddr_in dest_addr;
struct sockaddr_in from;
struct timeval tvrecv;
pid_t pid;

void statistics (int sig)
{
  double min = 0;
  double max = 0;
  double avg = 0;
  int i;
  
  min = max = temp_rtt[0];
  if (nreceived > 0) {
      avg = all_time / nreceived;
  }
  for (i = 0; i < nreceived; i++) {
      if (temp_rtt[i] < min) {
          min = temp_rtt[i];
      } else if (temp_rtt[i] > max) {
          max = temp_rtt[i];
      }  
  }
  printf("\n------Ping %s statistics----\n", dest);
  printf("%d packets transmittted, %d received, %d%% packet loss, time %.f ms\n",
        nsend, nreceived, (nsend - nreceived) / (nsend * 100), all_time);
  printf("rtt min/avg/max = %.3f/%.3f/%.3fms\n", min, avg, max);
  close(sockfd);
  exit(1);
} 

unsigned short cal_chksum(unsigned short *addr, int len)
{
    unsigned short chksum;
    unsigned int sum = 0;
    while (len > 1) {
        sum += *addr++;
        len -= 2;
    }
    if (len == 1)
        sum += *(unsigned char*)addr;
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    chksum = ~sum;
    return (chksum);   
}

int pack_icmp(int pcak_no)
{
    int packsize;
    struct icmp *icmp;
    struct timeval *tval;

    icmp = (struct icmp*)sendpacket;
    icmp -> icmp_type = ICMP_ECHO;
    icmp -> icmp_code = 0;
    icmp -> icmp_cksum = 0;
    icmp -> icmp_seq = pcak_no;
    icmp -> icmp_id = pid;
    packsize = ICMP_HEADER_LEN + DATA_LEN;
    tval = (struct timeval*)icmp -> icmp_data;
    gettimeofday(tval, NULL);
    icmp -> icmp_cksum = cal_chksum((unsigned short*)icmp, packsize);

	return packsize;
}

void send_packet(int sockfd)
{
    int packsize;

    if (nsend < MAX_NO_PACKETS) {
        nsend++;
        packsize = pack_icmp(nsend);
        if ((sendto(sockfd, sendpacket, packsize, 0, 
                         (struct sockaddr *)&dest_addr, sizeof(dest_addr))) < 0) {
            perror("sendto error");
        }
    }
}

void tv_sub(struct timeval *recvtime, struct timeval *sendtime)
{
    long sec = recvtime -> tv_sec - sendtime -> tv_sec;
    long usec = recvtime -> tv_usec - sendtime -> tv_usec;

    if (usec >= 0) {
        recvtime -> tv_sec = sec;
        recvtime -> tv_usec = usec;
    } else {
        recvtime -> tv_sec = sec - 1;
        recvtime -> tv_usec = -usec;
    }
}

int unpack_icmp(char *buf, int len)
{
    int iphdrlen;
    struct ip *ip;
    struct icmp *icmp;
    struct timeval *tvsend;
    double rtt;

    ip = (struct ip *)buf;
    iphdrlen = ip -> ip_hl << 2;
    icmp = (struct icmp *)(buf + iphdrlen);
    len -= iphdrlen;
    if (len < 8) {
        printf("ICMP packet's length is less than 8\n");
        return -1;
    }
    if ((icmp -> icmp_type == ICMP_ECHOREPLY) && (icmp -> icmp_id == pid)) {
        tvsend = (struct timeval *)icmp -> icmp_data;
        tv_sub(&tvrecv, tvsend);
        rtt = tvrecv.tv_sec * 1000 + tvrecv.tv_usec / 1000;
        temp_rtt[nreceived] = rtt;
        all_time += rtt;
        printf("%d bytes from %s: icmp_seq = %u ttl = %d time = %.1f ms\n", 
                len, inet_ntoa(from.sin_addr),
                icmp -> icmp_seq, ip -> ip_ttl, rtt);
    }

    return 0;
}

void recv_packet(int sockfd)
{
    int n, fromlen;
    fromlen = sizeof(from);
    if (nreceived < nsend) {
        if ((n = recvfrom(sockfd, recvpacket, sizeof(recvpacket), 0,
                (struct sockaddr *)&from, &fromlen)) < 0) {
            perror("recvfrom error");
        }

        gettimeofday(&tvrecv, NULL);
        unpack_icmp(recvpacket, n);
        nreceived++;
    }
}

int main(int argc, char const *argv[])
{
    struct hostent *host;
    unsigned long inaddr = 0;

    dest = argv[1];
    if (argc < 2) {
        printf("usage: %s Hostname/IP address\n", argv[0]);
        exit(1);
    }

    if((sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket error");
        exit(1);
    }

    bzero(&dest_addr, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    if (inet_addr(dest) == INADDR_NONE) {
        if ((host = gethostbyname(dest)) == NULL) {
            perror("gethostbyname error");
            exit(1);
        }
        dest = host -> h_name;
        memcpy((char *)&dest_addr.sin_addr, host -> h_addr, host -> h_length);
    } else {
        dest_addr.sin_addr.s_addr = inet_addr(dest);
    }
    pid =getpid();
    printf("PING %s(%s) %d(%d) bytes of data.\n", dest,
            inet_ntoa(dest_addr.sin_addr), DATA_LEN, IP_HEADER_LEN + ICMP_HEADER_LEN + DATA_LEN);
    signal(SIGINT, statistics);
    while (nsend < MAX_NO_PACKETS) {
        send_packet(sockfd);
        recv_packet(sockfd);
        sleep(1);
    }

    return 0;
}
