/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-23 13:21:33
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-24 19:14:37
 */
#include <stdio.h>
#include <pwd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <assert.h>
#define LINE_SIZE 1024 // 命令最大长度
#define NUM 32		   // 命令拆分后的最大个数
#define ARGC_SIZE 32   // 命令行参数的最大个数
#define LEFT "["
#define RIGHT "]"
#define LABLE "#"
#define DELIM " "
#define EXIT_CODE 44
int lastcode = 0;
int quit = 0;
extern char **environ;
char commandline[LINE_SIZE]; // 存储命令
char *argv[ARGC_SIZE];

char pwd[LINE_SIZE];

// 自定义环境变量表
char myenv[LINE_SIZE];
// 自定义本地变量表

const char *getusername()
{
	return getenv("USER");
}
const char *gethostname()
{
	return getenv("HOSTNAME");
}
// const char *getpwd()
// {
// 	return getenv("PWD");
// }

void getpwd()
{
	getcwd(pwd, sizeof(pwd));
}

void interact(char *cline, int size)
{
	getpwd();
	printf(LEFT "%s@%s:%s" RIGHT "" LABLE " ", getusername(), gethostname(), pwd);
	char *s = fgets(cline, size, stdin); // 标准输入就是键盘 获取到的是c风格的字符串
	assert(s != NULL);
	// "abcd\n\0"
	cline[strlen(cline) - 1] = '\0'; // 最后一个字符是\n 改成\0
}

int splitstring(char _commandline[], char *_argv[])
{
	int i = 0;
	_argv[i++] = strtok(_commandline, DELIM);
	while ((_argv[i++] = strtok(NULL, DELIM)))
		;
	return i - 1;
}

void normal_execute(char *_argv[]) // 修改参数的名字，不和全局变量冲突
{
	pid_t id = fork(); // 创建子进程执行命令
	if (id < 0)
	{
		perror("fork");
	}
	else if (id == 0)
	{
		// child
		// 0下标保存的就是程序名字，p表示会自动去环境变量中寻找
		// execvpe(_argv[0], _argv, environ); // child进行程序替换
		execvp(_argv[0], _argv); // child进行程序替换
		exit(EXIT_CODE);		 // 替换失败的退出码 替换失败直接退出
	}
	else
	{
		// parent
		int status = 0;
		pid_t ret = waitpid(id, &status, 0); // shell等待child退出
		if (ret == id)
		{																			 // 等待成功
			printf("wait succes, ret:%d, exit code:%d\n", ret, WEXITSTATUS(status)); // 打印child的退出码
			lastcode = WEXITSTATUS(status);
		}
	}
}

int buildCommand(char *_argv[], int _argc)
{
	if (_argc == 2 && strcmp(_argv[0], "cd") == 0)
	{
		chdir(argv[1]);
		getpwd();
		sprintf(getenv("PWD"), "%s", pwd);
		return 1;
	}
	// 由于只维护了一个myenv，第二次export，上一次的export的环境变量就会被覆盖
	else if (_argc == 2 && strcmp(_argv[0], "export") == 0)
	{
		strcpy(myenv, _argv[1]);
		putenv(myenv);
		return 1;
	}
	else if (_argc == 2 && strcmp(_argv[0], "echo") == 0)
	{
		if (strcmp(_argv[1], "$?") == 0)
		{
			printf("%d\n", lastcode);
			lastcode = 0;
		}
		else if (*_argv[1] == '$')
		{
			char *val = getenv(_argv[1] + 1);
			if (val != NULL)
				printf("%s\n", val);
		}
		else
		{
			printf("%s\n", _argv[1]);
		}

		return 1;
	}

	// 特殊处理一下ls
	if (strcmp(_argv[0], "ls") == 0)
	{
		_argv[_argc++] = "--color";
		_argv[_argc] = NULL;
	}
	return 0;
}
int main()
{

	while (!quit)
	{
		// 1.
		// 2. 交互问题,获取命令行, ls -a -l > myfile / ls -a -l >> myfile / cat < file.txt
		interact(commandline, sizeof(commandline));
		printf("echo: %s\n", commandline);

		// commandline -> "ls -a -l -n\0" -> "ls" "-a" "-l" "-n"
		// 3. 子串分割的问题，解析命令行
		int argc = splitstring(commandline, argv);
		if (argc == 0)
			continue;

		// 4. 指令的判断
		// 内键命令，本质就是一个shell内部的一个函数
		int n = buildCommand(argv, argc);

		// ls -a -l | wc -l
		// 4.0 分析输入的命令行字符串，获取有多少个|, 命令打散多个子命令字符串
		// 4.1 malloc申请空间，pipe先申请多个管道
		// 4.2 循环创建多个子进程，每一个子进程的重定向情况。最开始. 输出重定向, 1->指定的一个管道的写端
		// 中间：输入输出重定向， 0标准输入重定向到上一个管道的读端 1标准输出重定向到下一个管道的写端
		// 最后一个：输入重定向，将标准输入重定向到最后一个管道的读端
		// 4.3 分别让不同的子进程执行不同的命令--- exec* --- exec*不会影响该进程曾经打开的文件，不会影响预先设置好的管道重定向
		// 5. 普通命令的执行
		if (!n)
			normal_execute(argv);
	}
	return 0;
}
