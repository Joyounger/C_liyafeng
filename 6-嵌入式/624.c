
int main(int argc, char const *argv[])
{
	#ifndef __MSDOS__
	const char name[] = "/root/new/table";
	#else
	const char name[] = "\root\new\table";
	#endif

	return 0;
}