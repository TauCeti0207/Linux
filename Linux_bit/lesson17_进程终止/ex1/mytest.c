/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-07 20:53:47
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-21 08:19:06
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	printf("Before: pid is %d\n", getpid());
	if ((pid = fork()) == -1)
	{
		perror("fork()");
		exit(1);
	}
	printf("After:pid is %d, fork return %d\n", getpid(), pid);
	sleep(1);
	return 0;
}