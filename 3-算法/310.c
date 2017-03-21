#include <stdio.h>

void selectsort(int a[], unsigned int len)
{
    int i = 0, j = 0;
    int temp = 0, min = 0;

    for (; i < len; i++)
    {
        min = i;
        for (j = i + 1; j < len; j ++)
        {
            if (a[min] > a[j])
            {
                temp = a[min];
                a[min] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int test[] = {10, 23, 21, 18, 7, 2, 56, 28, 21};
    unsigned int n = sizeof(test) / sizeof(int);
    int i = 0;

    printf("before select sort:\n");
    while (i < n)
    {
        printf("%3d", test[i++]);
    }

    selectsort(test, n);
    printf("\nAfter select sort:\n");
    i = 0;
    while (i < n)
    {
        printf("%3d", test[i++]);
    }

    return 0;
}

