#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	while (1)
	{
		printf("I am a procee! pid:%d ppid:%d\n", getpid(), getppid());
		sleep(1);
	}
	return 0;
}