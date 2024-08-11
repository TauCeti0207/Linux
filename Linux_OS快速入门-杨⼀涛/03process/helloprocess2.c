/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-09 22:17:33
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-09 22:20:41
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t cid; // child pid

	printf("Before fork Process id:%d\n", getpid());

	cid = fork();

	if (cid == 0)
	{ // child process
		printf("Child process id (my parent pid is %d):%d\n", getppid(), getpid());
		for (int i = 0; i < 30; i++)
		{
			printf("hello\n");
		}
	}
	else
	{ // parent process
		printf("Parent Process id: %d\n", getpid());
		for (int i = 0; i < 30; i++)
		{
			printf("world\n");
		}

		wait(NULL); // 等待子进程结束
	}

	return 0;
}