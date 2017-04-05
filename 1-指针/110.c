// date:17.4.5
// author: linyang <942510346@qq.com>

#include <stdio.h>
#include <assert.h>

void calcCharCount(char *s)
{
    int i = 0, j = 0, max = 0;
    int count[26] = { 0 };
    int flag = 0;
    int flag2 = 0;
    assert(s);
    for ( i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            max = (++count[(int)s[i] - 97]) > max ? count[(int)s[i] - 97] : max;
        }
    }
    for (i = 1; i <= max; i++)
    {
        for (j = 0; j < 25; j++)
        {
            if (count[j] == i)
            {
                printf("%c", (char)(j + 97));
                flag = 1;
            }
        }

        if (flag)
        {
            printf(":%2d\n", i);
            flag = 0;
            flag2 = 1;
        }
    }
    if (!flag2)
    {
        printf("No matched!\n");
    }
}


int main(int argc, char const *argv[])
{
    char *s = "mike.lee@ChinaBejing";
    calcCharCount(s);

    return 0;
}

/*
aghjklm: 1
n: 2
i: 3
e: 4
*/