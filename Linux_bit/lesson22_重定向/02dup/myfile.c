/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-24 23:11:34
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-25 22:28:02
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define filename "log.txt"

int main1()
{
	int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
	{
		perror("open error\n");
		return 1;
	}
	dup2(fd, 1); // fd拷贝到1，new是old的拷贝
	printf("hello linux\n");
	fflush(stdout); // 刷新标准输出流（stdout）的缓冲区，确保所有待写入的数据立即被写入到目的地。
	close(fd);
	return 0;
}

int main2()
{
	int fd = open(filename, O_RDONLY, 0666);
	if (fd < 0)
	{
		perror("open error\n");
		return 1;
	}

	dup2(fd, 0);

	char inbuffer[1024];
	ssize_t s = read(0, inbuffer, sizeof(inbuffer) - 1);
	if (s > 0)
	{
		inbuffer[s] = '\0';
		printf("echo: %s", inbuffer);
	}
	close(fd);
	return 0;
}

int main()
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd < 0)
	{
		perror("open error\n");
		return 1;
	}
	dup2(fd, 1); // 将标准输出重定向到fd
	printf("fd: %d\n", fd);
	printf("hello printf\n");
	fprintf(stdout, "hello fprintf\n"); // 库函数fprintf
	close(fd);
	return 0;
}