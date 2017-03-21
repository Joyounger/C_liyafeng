#include <stdio.h>
#include <string.h>

#define MAX_RECEIVE_LEN 65
int char2int(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return c - 'A' + 10;
}

unsigned short cal_crc(unsigned char* p, int len)
{
    unsigned short ret = 0xFFFF;
    int i = 0, k = 0;
    for (; i < len; ++i)
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
    int saveadd = 0, func = 0, startadd = 0, num = 0, i = 0, len = 0, k = 0;
    unsigned short val = 0;
    unsigned char receive[MAX_RECEIVE_LEN];
    unsigned char receivetmp[MAX_RECEIVE_LEN];
    unsigned char str[MAX_RECEIVE_LEN];
    unsigned char fstr[4];
    float *pf = NULL;

    while(EOF != scanf("%d,%d,%d,%d", &saveadd, &func, &startadd, &num))
    {
        str[0] = saveadd;
        str[1] = func;
        str[3] = startadd & 0xFF;
        startadd >>= 8;
        str[2] = startadd & 0xFF;
        str[5] = num & 0xFF;
        num >>= 8;
        str[4] = num & 0xFF;
        val = cal_crc(str, 6);
        str[7] = val & 0xFF;   
        val >>= 8;
        str[6] = val & 0xFF;
        for (i = 0; i < 8; ++i)
        {
            printf("%02X", str[i]);
        }
        printf("\n");
        scanf("%s", receivetmp);
        len = strlen((char*)receivetmp) / 2;
        for (i = 0; i < len; ++i)
        {
            receive[i] = (unsigned char)(char2int(receivetmp[i*2]) * 16
                + char2int(receivetmp[i*2 + 1]));
        }
        val = cal_crc(receive, len - 2);
        if ((val & 0xFF) != receive[len - 1] || ((val >> 8) & 0xFF) != 
            receive[len - 2])
        {
            printf("CRC_ERROR\n");
            continue;
        }
        k = 2;
        num = receive[k] / 4;
        ++k;
        for (i = 0; i < num; ++i)
        {
            fstr[0] = receive[k + 3];
            fstr[1] = receive[k + 2];
            fstr[2] = receive[k + 1];
            fstr[3] = receive[k];
            pf = (float*)(fstr);
            printf("%.1f", *pf);
            if (i != num - 1)
            {
                printf(",");
            }
            k += 4;
        }
        if (0 != num)
        {
            printf("\n");
        }
    }
    return 0;
}       