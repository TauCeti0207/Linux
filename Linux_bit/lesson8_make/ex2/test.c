#include <stdio.h>
#include <unistd.h>
int main()
{
	printf("hello Linux\n"); // 1
	fflush(stdout);			 // 立即刷新标准输出缓冲区。
	sleep(1);				 // 2
	return 0;
}