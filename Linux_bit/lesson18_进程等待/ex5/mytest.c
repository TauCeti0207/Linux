/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-21 13:10:42
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-21 13:34:10
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t id = fork();

	if (id == 0)
	{
		// 子进程
		int cnt = 5;
		while (cnt)
		{
			printf("我是子进程，我的pid：%d，我的ppid：%d cnt: %d\n", getpid(), getppid(), cnt--);
			sleep(1);
		}
		exit(10);
	}
	else if (id > 0)
	{
		// 父进程
		int status = 0;
		while (1)
		{
			pid_t ret = waitpid(-1, &status, WNOHANG); // 基于非阻塞的轮询等待方案：WNOHANG
			if (ret > 0)
			{
				printf("等待成功！%d，exit sig：%d，exit code：%d\n", ret, status & 0x7F, (status >> 8) & 0xFF);
				break;
			}
			else if (ret == 0) // 调用函数立即返回才会执行这个语句
			{
				// 等待成功了，但是子进程没有退出
				printf("子进程未准备好，父进程做其他事情...\n");
				sleep(1);
			}
			else
			{
				// 出错了
				printf("error1\n");
			}
		}
	}
	else
	{
		// 错误情况2
		printf("error2\n");
	}
	return 0;
}