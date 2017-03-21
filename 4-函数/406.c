#include <stdio.h>

void bublesort(int a[], int n)
{
    int i,j;
    int temp = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n-i; j++)
        {
            if (a[j] < a[j - 1])
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

void qsort(int a[], int n)
{
    int i = 0, j = n-1, k = a[i];

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
            while (i < j && a[j] < k)
            {
                i++;
            }
            if (i < j)
            {
                a[j--] = a[i];
            }
        }
        a[i] = k;
        qsort(a, i);
        qsort(a + i + 1, n - i - 1);
    }
}


void sort_data(int a[], int n, void (*sort)(int *, int))
{
    sort(a, n);
}

int main()
{
    int test[] = {10, 23, 21, 18, 7, 2, 56, 28,21};
    unsigned int n = sizeof(test) / sizeof(int);
    int i = 0;
    void (*f)(int *, int);

    if (n < 50)
    {
        f = qsort;
    } else {
        f = bublesort;
    }
    printf("before sort:\n");
    while (i < n)
    {
        printf("%3d", test[i++]);
    }
    sort_data(test, n, f);
    printf("\nafter sort:\n");
    i = 0;
    while(i < n)
        printf("%3d", test[i++]);

    return 0;
}


