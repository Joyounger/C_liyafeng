#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 20
#define swap(a, b) (a) = (a) + (b); (b) = (a) - (b); (a) = (a) - (b)

int permutation(char *word, int len)
{
    int i, left, right;
    int flag= 1, count = 1;

    printf("%10s ", word);
    while (flag)
    {
        left = right = -1;
        for (i = len - 1; i > 0; --i)
        {
            if (word[i - 1] < word[i])
            {
                left = i - 1;
                break;
            }
        }
        if (left < 0)
        {
            flag = 0;
            break;
        }
        for (i = len - 1; i >= left; --i)
        {
            if (word[i] > word[left])
            {
                right = i;
                break;
            }  
        }
        if (left != right)
        {
            swap(word[left], word[right]);
        }
        for (i = 0; i < (len - left - 1) / 2; i++)
        {
            if ((left + 1 + i) != (len - 1 - i))
            {
                swap(word[left + 1 + i], word[len - 1 -i]);
            }
        }
        printf("%10s ", word);
        if ((++count % 5) == 0)
        {
            printf("\n");
        }
    }
    return count;
}

int cmp (const void *sp1, const void *sp2)
{
    const char s1 = *(char *)sp1;
    const char s2 = *(char *)sp2;

    return (s1 > s2 ? 1 : s1 < s2 ? -1 : 0);
}

int main()
{
    char word[MAX_LEN];
    char bword[MAX_LEN];
    int len, count = 0;

    printf("please input a word:\n");
    scanf("%s", word);
    len = strlen(word);
    strcpy(bword, word);

    qsort(bword, len, sizeof(char), cmp);
    printf("\nword \"%s\" permutations:\n", word);
    count = permutation(bword, len);
    printf("\nword \"%s\" has %d different permutations.\n", word, count);
    
    return 0;
}