#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define swap(a, b) (a) = (a) + (b); (b) = (a) - (b); (a) = (a) - (b);

static char *gp;
static int count = 0;

void permutation(char w[], int m, int n)
{
    int i = 0;

    if (m < n - 1)
    {
        permutation(w, m + 1, n);
        for (i = m+1; i < n; i++)
        {
            swap(w[m], w[i]);
            permutation(w, m + 1, n);
            swap(w[m], w[i]);
        }
    } else if ((strstr(gp, w)) == NULL)
    {
        printf("%10s ", w);
        if ((++count % 5) == 0)
        {
            printf("\n");
        }
        strcat(gp, w);
        strcat(gp, ";");
    }
}

int main(void)
{
    int i, len;
    int plen;
    char word[20];

    printf("please input a word:\n");
    scanf("%s", word);
    len = strlen(word);
    plen = len + 1;
    for (i = 1; i < len + 1; i++)
    {
        plen *= i;
    }
    if ((gp = (char *)malloc(plen + 1)) == NULL)
    {
        return 0;
    }
    printf("\nword \"%s\" permutations:\n", word);
    permutation(word, 0, len);
    printf("\nword \"%s\" has %d different permutations.\n", word, count);
    free(gp);

    return 0;
}