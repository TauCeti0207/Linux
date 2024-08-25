/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-24 23:11:34
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-24 23:44:00
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	printf("pid:%d\n", getpid());
	FILE *fp = fopen("log.txt", "w");
	if (fp == NULL)
	{
		perror("fopen");
		return 1;
	}

	const char *message = "hello world\n";
	fwrite(message, strlen(message), 1, fp);
	fclose(fp);

	return 0;
}
