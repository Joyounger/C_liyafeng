// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int testmem(char *s)
{
	int len = strlen(s);
	char *p1;
	char *p2;

	assert(s);
	if (0 == len)
		return -1;

	p1 = (char *)malloc(len);
	if (NULL == p1)
		return -1;
	
	memcpy(p1, s, len);
	p2 = (char *)malloc(len);

	if(NULL == p2) {
		return -1;
	}
	p2 = p1;
	printf("%s\n", p2);
	free(p1);
	free(p2);
	p1 = p2 = NULL;

	return 0;
}


int main(int argc, char const *argv[])
{
	char *s = "1234567890";
	testmem(s);

	return 0;
}


/*
kolya@asus ~/src/C_liyafeng/2-内存 $ ./216
1234567890
*** Error in `./216': double free or corruption (fasttop): 0x0000000001035010 ***
======= Backtrace: =========
/lib/x86_64-linux-gnu/libc.so.6(+0x777e5)[0x7f15435fb7e5]
/lib/x86_64-linux-gnu/libc.so.6(+0x7fe0a)[0x7f1543603e0a]
/lib/x86_64-linux-gnu/libc.so.6(cfree+0x4c)[0x7f154360798c]
./216[0x400784]
./216[0x4007be]
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf0)[0x7f15435a4830]
./216[0x4005e9]
======= Memory map: ========
00400000-00401000 r-xp 00000000 08:01 20197883                           /home/kolya/src/C_liyafeng/2-内存/216
00600000-00601000 r--p 00000000 08:01 20197883                           /home/kolya/src/C_liyafeng/2-内存/216
00601000-00602000 rw-p 00001000 08:01 20197883                           /home/kolya/src/C_liyafeng/2-内存/216
01035000-01056000 rw-p 00000000 00:00 0                                  [heap]
7f153c000000-7f153c021000 rw-p 00000000 00:00 0 
7f153c021000-7f1540000000 ---p 00000000 00:00 0 
7f154336e000-7f1543384000 r-xp 00000000 08:01 5509571                    /lib/x86_64-linux-gnu/libgcc_s.so.1
7f1543384000-7f1543583000 ---p 00016000 08:01 5509571                    /lib/x86_64-linux-gnu/libgcc_s.so.1
7f1543583000-7f1543584000 rw-p 00015000 08:01 5509571                    /lib/x86_64-linux-gnu/libgcc_s.so.1
7f1543584000-7f1543743000 r-xp 00000000 08:01 5512706                    /lib/x86_64-linux-gnu/libc-2.23.so
7f1543743000-7f1543943000 ---p 001bf000 08:01 5512706                    /lib/x86_64-linux-gnu/libc-2.23.so
7f1543943000-7f1543947000 r--p 001bf000 08:01 5512706                    /lib/x86_64-linux-gnu/libc-2.23.so
7f1543947000-7f1543949000 rw-p 001c3000 08:01 5512706                    /lib/x86_64-linux-gnu/libc-2.23.so
7f1543949000-7f154394d000 rw-p 00000000 00:00 0 
7f154394d000-7f1543973000 r-xp 00000000 08:01 5512695                    /lib/x86_64-linux-gnu/ld-2.23.so
7f1543b48000-7f1543b4b000 rw-p 00000000 00:00 0 
7f1543b6f000-7f1543b72000 rw-p 00000000 00:00 0 
7f1543b72000-7f1543b73000 r--p 00025000 08:01 5512695                    /lib/x86_64-linux-gnu/ld-2.23.so
7f1543b73000-7f1543b74000 rw-p 00026000 08:01 5512695                    /lib/x86_64-linux-gnu/ld-2.23.so
7f1543b74000-7f1543b75000 rw-p 00000000 00:00 0 
7ffd85cd3000-7ffd85cf4000 rw-p 00000000 00:00 0                          [stack]
7ffd85d65000-7ffd85d67000 r--p 00000000 00:00 0                          [vvar]
7ffd85d67000-7ffd85d69000 r-xp 00000000 00:00 0                          [vdso]
ffffffffff600000-ffffffffff601000 r-xp 00000000 00:00 0                  [vsyscall]
已放弃
kolya@asus ~/src/C_liyafeng/2-内存 $ 
*/