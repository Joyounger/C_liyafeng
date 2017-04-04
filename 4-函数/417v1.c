// date:17.4.5
// author: linyang <942510346@qq.com>
// all combinations of a word

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


/*
kolya@asus ~/src/C_liyafeng/4-函数 $ ./417v1
please input a word:
apple

word "apple" permutations:
     apple      appel      aplpe      aplep      apelp 
     apepl      alppe      alpep      alepp      aeplp 
     aeppl      aelpp      paple      papel      palpe 
     palep      paelp      paepl      ppale      ppael 
     pplae      pplea      ppela      ppeal      plpae 
     plpea      plape      plaep      pleap      plepa 
     pepla      pepal      pelpa      pelap      pealp 
     peapl      lppae      lppea      lpape      lpaep 
     lpeap      lpepa      lappe      lapep      laepp 
     lepap      leppa      leapp      eppla      eppal 
     eplpa      eplap      epalp      epapl      elppa 
     elpap      elapp      eaplp      eappl      ealpp 

word "apple" has 60 different permutations.
*/