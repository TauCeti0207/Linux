/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-21 09:50:02
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-21 10:06:06
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
int main()
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
		int cnt = 5;
		while (cnt)
		{
			printf("我是子进程，我正在运行...pid:%d ppid:%d cnt:%d\n", getpid(), getppid(), cnt);
			cnt--;
			sleep(1);
		}
	}
	else
	{
		// parrent
		int cnt = 10;
		while (cnt)
		{
			printf("我是父进程，我正在运行...我准备等待子进程了! pid:%d ppid:%d cnt:%d\n", getpid(), getppid(), cnt);
			cnt--;
			sleep(1);
		}
		pid_t ret = wait(NULL);
		// wait(NULL)函数的作用是等待任意一个子进程结束，并返回退出状态
		// 它的参数为NULL，表示不关心子进程的退出状态。如果传入一个指向整型变量的指针，wait() 函数将会把子进程的退出状态值存储在这个整型变量中，我们可以通过这个状态值来判断子进程是否正常结束。
		if (ret < 0)
			printf("等待失败\n");
		else if (ret == id)
		{
			printf("等待成功，ret: %d\n", ret);
		}
		// sleep(10);
	}
	return 0;
}