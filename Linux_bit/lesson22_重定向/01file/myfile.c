/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-24 23:11:34
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-25 21:57:45
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
	close(2);
	int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
	{
		perror("open error\n");
		return 1;
	}
	printf("fd: %d\n", fd);

	int cnt = 5;
	const char *msg = "hello world\n";
	while (cnt)
	{
		write(fd, msg, strlen(msg));
		cnt--;
	}
	close(fd);
	return 0;
}

int main2()
{
	close(1);
	int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
	{
		perror("open error\n");
		return 1;
	}
	printf("fd: %d\n", fd);

	int cnt = 5;
	const char *msg = "hello world\n";
	while (cnt)
	{
		write(1, msg, strlen(msg));
		cnt--;
	}
	close(fd);
	return 0;
}

int main()
{
	close(1);
	int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
	{
		perror("open error\n");
		return 1;
	}
	printf("hello linux\n");
	fflush(stdout);
	close(fd);
	return 0;
}