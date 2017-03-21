#include <stdio.h>

unsigned short modbus_crc(unsigned char* p, int len)
{
    unsigned short ret = 0xFFFF;
    int i = 0;
    int k = 0;
    
    for (i = 0; i < len; ++i)
    {
        ret ^= p[i];
        for (k = 0; k < 8; ++k)
        {
            ret = (ret & 0x01) ? ((ret >> 1) ^ 0xA001) : (ret >> 1);
        }
    }
    ret = ((ret & 0x00FF) << 8) | ((ret & 0xFF00) >> 8);
    return ret;
}


int main()
{
    unsigned char input[] = {0x01, 0x04, 0x0d, 0x28, 0x00, 0x02, 0x01,
        0x02, 0x00, 0x53, 0x00, 0x01};
    unsigned short out = 0;
    int i = 0;
    int len = sizeof(input);

    out = modbus_crc(input, sizeof(input));
    printf("Input: ");
    for (i = 0; i < len; i++)
    {
        printf(" 0x%.2X", input[i]);
    }
    printf("\nModbus CRC is: 0x%.4X\n", out);
    return 0;
}


