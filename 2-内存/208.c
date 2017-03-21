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