#include <stdio.h>

void qsort(int a[], int n)
{
    int i = 0, j = n - 1, k = a[i];

    if (0 < n - 1)
    {
        while (i < j)
        {
            while (i < j && a[j] > k)
            {
                j--;
            }
            if (i < j)
            {
                a[i++] = a[j];
            }
            while (i < j && a[i] < k)
            {
                i++;
            }
            if (i < j)
            {
                a[j--] = a[i];
            }
            
        }
        a[i] = k;
        qsort(a, i - 1);
        qsort(a + i +1, n - i - 1);
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
    qsort(test, n);
    printf("\nAfter insert sort:\n");
    i = 0;
    while (i < n)
    {
        printf("%3d", test[i++]);
    }

    return 0;
}