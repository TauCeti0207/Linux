#include <stdio.h>

#define _DEBUG_ 1
int main(int argc, const char* argv[])
{
#if _DEBUG_
	printf("hello world\n");
#else
	printf("welcome to dalian\n");
#endif
	return 0;
}
