/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-21 13:10:42
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-22 11:38:58
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define TASK_NUM 3
typedef void (*task_t)();
task_t tasks[TASK_NUM];

void task1()
{
	printf("打印日志任务, pid: %d\n", getpid());
}

void task2()
{
	printf("检测网络健康状态任务, pid: %d\n", getpid());
}

void task3()
{
	printf("检测磁盘空间任务, pid: %d\n", getpid());
}

void init_task()
{
	for (size_t i = 0; i < TASK_NUM; i++)
	{
		tasks[i] = NULL;
	}
}

int add_task(task_t task)
{
	int pos = 0;
	for (; pos < TASK_NUM; pos++)
	{
		if (tasks[pos] == NULL)
		{
			break;
		}
	}
	if (pos == TASK_NUM)
	{
		return -1;
	}
	tasks[pos] = task;
	return 0;
}

void del_task(int pos)
{
	if (pos >= 0 && pos < TASK_NUM)
	{
		tasks[pos] = NULL;
	}
}

void check_task()
{
	for (size_t i = 0; i < TASK_NUM; i++)
	{
		if (tasks[i])
		{
			printf("任务%ld存在\n", i + 1);
		}
	}
}

void update_task(int pos, task_t new_task)
{
	if (pos >= 0 && pos < TASK_NUM)
	{
		tasks[pos] = new_task;
	}
}

void execute_task()
{
	for (size_t i = 0; i < TASK_NUM; i++)
	{
		if (!tasks[i])
			continue;
		tasks[i]();
	}
}
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
		init_task();
		add_task(task1);
		add_task(task2);
		add_task(task3);
		while (1)
		{
			pid_t ret = waitpid(-1, &status, WNOHANG); // 基于非阻塞的轮询等待方案：WNOHANG
			if (ret > 0)
			{
				// 7f 0111 1111 低7位表示的就是退出信号
				// printf("等待成功，ret: %d, exit sig: %d, exit code: %d\n", ret, status & 0x7F, (status >> 8) & 0xFF);

				if (WIFSIGNALED(status))
				{
					printf("子进程被信号终止，信号: %d\n", WTERMSIG(status));
				}
				else if (WIFEXITED(status))
				{
					printf("子进程正常退出，退出码: %d\n", WEXITSTATUS(status));
				}
				break;
			}
			else if (ret == 0) // 调用函数立即返回才会执行这个语句
			{
				// 等待成功了，但是子进程没有退出
				printf("子进程未准备好，父进程做其他事情...\n");
				execute_task();
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