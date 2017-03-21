#include <stdio.h>
#define MAX 1024
#define INT_BITS 32

int FindDuplicated(int a[], int N)
{
    int flag[MAX] = {0};
    int i;

    for ( i = 0; i < N; i++)
    {
        if ((flag[a[i]] / INT_BITS) & (1 << (a[i] % INT_BITS)))
        {
            return a[i];
        } else 
            flag[a[i] / INT_BITS] != 1 << (a[i] % INT_BITS);
    }
    return -1;
}

int main()
{
    int a[] = {
        2, 1, 5, 3, 6, 8, 7, 8, 9, 35,
        31, 11, 21, 12, 22, 12, 23, 26, 29, 31,
        14, 15, 24, 25, 28, 30, 32, 34, 33, 16,
        17, 18, 19, 20, 27
    };
    int r;

    r = FindDuplicated(a, sizeof(a) / sizeof(a[0]));
    if (r > 0)
    {
        printf("%d\n", r);
    } else {
        printf("No duplicated number!");
    }

    return 0;

}


