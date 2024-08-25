/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-25 10:31:34
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-25 12:49:25
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main()
{
	umask(0);
	int fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
	// O_CREAT表示文件不存在就创建文件
	if (fd < 0)
	{
		perror("open");
		return -1;
	}
	printf("fd = %d\n", fd);

	const char *message = "hello file system call\n";
	write(fd, message, strlen(message));

	close(fd);
	return 0;
}