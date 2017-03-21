#include <stdio.h>

static int R;
void set_bitN(unsigned int N)
{
    N = (N > 31) ? (N % 32) : N;
    R |= (1 << N);
}

void clear_bitN(unsigned int N)
{
    N = (N > 31) ? (N % 32) : N;
    R &= ~(1 << N);
}

int main()
{
    R = 0xF0F0;
    printf("for exampke in 0x%X\n", R);
    set_bitN(3);
    printf("Ater set bit 3 is 0x%X\n", R);
    clear_bitN(7);
    printf("Ater clear bit 7 is 0x%X\n", R);

    return 0;
}