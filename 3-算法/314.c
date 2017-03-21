#include <stdio.h>

#define R (1 << 0)
#define G (1 << 1)
#define B (1 << 2)
#define Y (1 << 3)

void rollCubeZ90(unsigned short c[])
{
    unsigned short tmp = c[0];
    c[0] = c[3];
    c[3] = c[1];
    c[1] = c[2];
    c[2] = tmp;
}

void rollCubeX180(unsigned short c[])
{
    unsigned short tmp = c[4];
    c[4] = c[5];
    c[5] = tmp;
    tmp = c[2];
    c[2] = c[3];
    c[3] = tmp;
}

void rollCubeX90(unsigned short c[])
{
    unsigned short tmp = c[2];
    c[2] = c[4];
    c[4] = c[3];
    c[3] = c[5];
    c[5] = tmp;
}

void rollCubeY90(unsigned short c[])
{
    unsigned short tmp = c[0];
    c[0] = c[4];
    c[4] = c[1];
    c[1] = c[5];
    c[5] = tmp;
}

unsigned short statHash(unsigned short c[], unsigned short n)
{
    unsigned short h = 0;
    if (n % 4 == 0)
    {
        if (n)
        {
            rollCubeZ90(c);
        }
        switch(n) {
            case 0:
                break;
            case 4:
            case 8:
            case 12:
                rollCubeY90(c);
                break;
            case 16:
                rollCubeX90(c);
                break;
            case 20:
                rollCubeX180(c);
                break;
            default:
                printf("wrong state\n");
        }
    } else {
        rollCubeZ90(c);
    }

    h = (c[0] << 12) + (c[1] << 8) + (c[2] << 4) + c[3];

    return h;
}

char color(unsigned short x)
{
    char c = 0;

    switch(x) {
        case R:
            c = 'R';
            break;
        case G:
            c = 'G';
            break;
        case B:
            c = 'B';
            break;
        case Y:
            c = 'Y';
            break;
        default:
            printf("wrong color\n");
    }
    return c;
}

void printfCubes(unsigned short c[][6])
{
    int i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%3c", color(c[i][j]));
        }
        printf("\n");
    }
}

int main()
{
    unsigned short c0 = 0, c1 = 0, c2 = 0, c3 = 0;

    unsigned short i, j, k, l;
    unsigned short c[][6] = {
        {R, B, G, Y, B, Y},
        {R, G, G, Y, B, B},
        {Y, B, R, G, Y, R},
        {Y, G, B, R, R, R}
    };
    int count = 0;

    for (i = 0; i < 24; i++)
    {
        c0 = statHash(c[0], i);
        for (j = 0; j < 24; j++)
        {
            c1 = statHash(c[1], j);
            for (k = 0; k < 24; k++)
            {
                c2 = statHash(c[2], k);
                for (l = 0; l < 24; l++)
                {
                    c3 = statHash(c[3], l);
                    if ((c0 | c1 | c2 | c3) == 0xFFFF)
                    {
                        printf("meet permutation No.%d\n", ++count);
                        printfCubes(c);
                    }
                }
            }
        }
    }

    return 1;
}