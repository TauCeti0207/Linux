/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-05 14:59:17
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-05 15:00:15
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	pid_t id = fork();
	if (id == 0)
	{
		// child
		while (1)
		{
			printf("I am child process, my pid: %d, my ppid: %d\n", getpid(), getppid());
			sleep(1);
		}
	}
	else
	{
		while (1)
		{
			printf("I am parent process, my pid: %d, my ppid: %d\n", getpid(), getppid());
			sleep(1);
			printf("\n");
		}
	}

	return 0;
}