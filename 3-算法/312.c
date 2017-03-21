#include <stdio.h>

void insertsort(int a[], unsigned int n)
{
    int i = 0, j = 0;
    int min = 0;

    for (i = 0; i < n; i++)
    {
        min = a[i];
        for (j = i - 1; (j >= 0) && (a[j] > min); j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = min;
    }
}

int main()
{
    int test[] = {10, 23, 21, 18, 7, 2, 56, 28, 21};
    unsigned int n = sizeof(test) / sizeof(int);
    int i = 0;

    printf("before insert sort: \n");
    while (i < n)
    {
        printf("%3d", test[i++]);
    }
    insertsort(test, n);
    printf("\nAfter insert sort:\n");
    i = 0;
    while (i < n)
    {
        printf("%3d", test[i++]);
    }

    return 0;
}