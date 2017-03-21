#include <stdio.h>

unsigned short ipCksum(unsigned short *addr, int len)
{
    unsigned short cksum;
    unsigned int sum = 0;

    while(len > 1) {
        sum += *addr++;
        len -= 2;
    }

    if (len == 1)
    {
        sum += *(unsigned char *)addr;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    cksum = ~sum;
    return cksum;
}

int main()
{
    unsigned short iph[] = {0x4500, 0x00ad, 0x7755, 0x4000, 0x8006, 0x0000, 0x0a97, 0x7819, 0x0a97, 0x781d};
    unsigned short cksum;

    cksum = ipCksum(iph, 20);
    printf("%X\n", cksum);
    iph[5] = cksum;
    cksum = ipCksum(iph, 20);
    if (cksum)
    {
        printf("checksum is incorrect!\n");
    }
    else {
        printf("checksum is correct!\n");
    }
       
    return 0;
}
