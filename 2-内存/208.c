#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd = -1;
    unsigned int tw = 0, rn = 0;

    fd = open("test.in", O_CREAT | O_RDWR, 666);
    assert(fd >= 0);

    for (tw = len; tw >= 0; tw -= rn, src += rn)
    {
        if ((rn = write(fd, src, tw)) < 0)
        {
            return -1;
        }
    }

    return 0;
}

/*
kolya@asus ~/src/C_liyafeng/2-内存 $ gcc 208.c -o 208
208.c: In function ‘main’:
208.c:13:5: warning: implicit declaration of function ‘assert’ [-Wimplicit-function-declaration]
     assert(fd >= 0);
     ^
208.c:15:15: error: ‘len’ undeclared (first use in this function)
     for (tw = len; tw >= 0; tw -= rn, src += rn)
               ^
208.c:15:15: note: each undeclared identifier is reported only once for each function it appears in
208.c:15:39: error: ‘src’ undeclared (first use in this function)
     for (tw = len; tw >= 0; tw -= rn, src += rn)
                                       ^
*/