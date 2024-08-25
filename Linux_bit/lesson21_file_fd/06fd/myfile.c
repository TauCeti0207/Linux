/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-25 10:31:34
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-25 12:57:12
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
	int fd1 = open("fd1.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
	int fd2 = open("fd2.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
	int fd3 = open("fd3.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);

	printf("fd1 = %d\n", fd1);
	printf("fd2 = %d\n", fd2);
	printf("fd3 = %d\n", fd3);

	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}