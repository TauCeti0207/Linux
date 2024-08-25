/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-24 23:11:34
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-24 23:37:44
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	printf("pid:%d\n", getpid());
	chdir("/home/yzq0207/Linux/Linux_bit/lesson21_file_fd");
	FILE *fp = fopen("change_cwd_log.txt", "w");
	if (fp == NULL)
	{
		perror("fopen");
		return 1;
	}

	const char *message = "hello world";
	fwrite(message, strlen(message), 1, fp);
	fclose(fp);
	while (1)
		;

	return 0;
}
