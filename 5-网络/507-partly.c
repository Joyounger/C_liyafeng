#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netonet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>

#define PACKEY_SIZE 4 * 1024
#define MAX_WAIT_TIME 5
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
struct sockaddr_in ftom;
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
  printf("\n------ping %s statistics----\n", dest);
  printf("%d packets transmittted, %d received, %d%% packet loss, time %.f ms\n",
        nsend, mreceived, (nsend - nreceived) / (nsend * 100), all_time);
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
    int package;
    struct icmp*icmp;
    struct timeval *tval;
	
}
