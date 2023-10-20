#include <stdio.h>

#define _DEBUG_
int main(int argc, const char* argv[])
{
#ifdef _DEBUG_
	printf("hello world\n");
#else
	printf("welcome to dalian\n");
#endif
	return 0;
}
