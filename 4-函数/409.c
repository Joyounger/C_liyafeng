#include <stdio.h>
#include <sys/time.h>

#define INLINE

#ifdef MACRO
#define max(a, b) a > b? a : b;
#else
#ifdef INLINE
static inline int max(int a, int b)
#else
int max(int a, int b)
#endif
{
    return a > b? a : b;
}
#endif

int main()
{

    int n, i, usec, m;
    struct timeval begin, end;
    
    for (i = 0; i < 5; i++)
    {
        gettimeofday(&begin, NULL);
        n = 99999999;
        while (n-- > 0)
        {
            m = max(6, 8);
        }
        gettimeofday(&end, NULL);
        usec = (end.tv_sec - begin.tv_sec) * 1000000 +
            (end.tv_usec - begin.tv_usec);
        printf("cost: %dus\n", usec);
    }

    return 0;
}