/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-22 13:41:20
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-22 13:50:51
 */
#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("before: I am a process, pid: %d, ppid: %d\n", getpid(), getppid());

	// execl("/usr/bin/ls", "ls", "-l", NULL);
	// execl("/usr/bin/top", "top", NULL); // without options
	int ret = execl("/usr/bin/lsss", "ls", "-l", NULL);

	printf("after: I am a process, pid: %d, ppid: %d, ret: %d\n", getpid(), getppid(), ret);

	return 0;
}