/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-23 09:38:57
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-23 11:01:07
 */
// myexec.c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	// 环境变量指针声明
	extern char **environ;
	putenv("PRIVATE_ENV=123456", NULL);
	printf("我是一个父进程,我的pid:%d\n", getpid());
	pid_t id = fork();
	if (id == 0)
	{
		// child process
		printf("我是一个子进程,我的pid:%d\n", getpid());
		char *const myenv[] = {(char *)"MYPATH=YouCanSeeMe!!", NULL};
		char *myargv[] = {"mycmd", "-a", "-b", "-c", NULL};
		// char *const argv[] = {(char *)"ls", (char *)"-a", (char *)"-l", (char *)NULL}; // 指针数组
		// execv("/usr/bin/ls",argv);
		// execlp("ls","ls","-a","-l",NULL);//两个ls 含义不同
		// execvpe("./mycmd", myargv, environ);
		// execv("./mycmd", myargv);
		execve("./mycmd", myargv, myenv);
		// execve("./mycmd", myargv, myenvp);

		// e:覆盖式的添加环境变量给目标进程
		// execle("./mycmd", "mycmd", "-a", "-b", "-c", NULL, environ);
		// execle("./mycmd", "mycmd", "-a", "-b", "-c", NULL, myenv);

		// execl("/home/yzq0207/Desktop/Linux/lesson17_230523/ex6/mycmd","mycmd",NULL);
		// execl("./mycmd", "mycmd", NULL); // 相对路径也可以的 调用cpp
		// execl("/usr/bin/python3", "python3", "helloPY.py", NULL); // 调用python
		// execl("/usr/bin/bash", "bash", "test.sh", NULL); // 调用脚本语言
		// 让子进程执行全新的程序
		// char* const argv[] = {(char*)"ls",(char*)"-a",(char*)"-l",(char*)NULL};//指针数组
		exit(1); // 只要执行了exit，意味着execl系列的函数就失败了
	}
	// parent process
	int status = 0;
	int ret = waitpid(id, &status, 0);
	if (ret == id)
	{
		sleep(2);
		printf("father process wait succes, father pid: %d ret: %d\n", getpid(), ret);
	}
	return 0;
}
