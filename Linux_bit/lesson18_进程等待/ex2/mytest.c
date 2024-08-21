/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-21 09:50:02
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-21 10:50:17
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

#define N 10

void runChild()
{
	int cnt = 3;
	while (cnt)
	{
		printf("我是子进程，我正在运行...pid:%d ppid:%d cnt:%d\n", getpid(), getppid(), cnt);
		cnt--;
		sleep(1);
	}
}

int main()
{
	for (size_t i = 0; i < N; i++)
	{
		pid_t id = fork();
		if (id < 0)
		{
			perror("fork");
			return 1;
		}
		else if (id == 0)
		{
			// child
			runChild();
			exit(0);
		}
		printf("create child process success! pid:%d ppid:%d\n", getpid(), getppid()); // 父进程才执行这行代码
	}

	// sleep(10);
	// wait
	for (size_t i = 0; i < N; i++)
	{
		// pid_t id = wait(NULL);
		pid_t id = waitpid(-1, NULL, 0); // 效果一样
		if (id > 0)
		{
			printf("wait %d success!\n", id);
		}
	}

	sleep(5);
	return 0;
}