/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-22 13:57:25
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-23 09:34:04
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	printf("I am a father process, my pid: %d, ppid: %d\n", getpid(), getppid());
	pid_t id = fork();
	if (id == 0)
	{
		// child process
		printf("I am a child process, my pid: %d, ppid: %d\n", getpid(), getppid());
		// 让子进程执行全新的程序
		char *const argv[] = {(char *)"ls", (char *)"-a", (char *)"-l", (char *)NULL}; // 指针数组
		// execv("/usr/bin/ls", argv);
		execvp("ls", argv);
		exit(1); // 只要执行了exit，意味着execl系列的函数就失败了
	}
	// parent process
	int status = 0;
	int ret = waitpid(id, &status, 0);
	if (ret == id)
	{
		sleep(2);
		printf("father process wait succes, father pid: %d, ret: %d\n", getpid(), ret);
	}
	return 0;
}