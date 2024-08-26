/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-24 23:11:34
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-26 17:30:58
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main1()
{
	printf("hello printf");
	char *str = "hello write\n";
	write(1, str, strlen(str));
	sleep(3);
	return 0;
}

int main2()
{
	const char *fstr = "hello fwrite\n";
	const char *str = "hello write\n";

	printf("hello printf\n");
	fprintf(stdout, "hello fprintf\n");
	fwrite(fstr, strlen(fstr), 1, stdout);
	write(1, str, strlen(str));

	fork();
	return 0;
}

int main3()
{
	const char *fstr = "hello fwrite";
	// const char *str = "hello write";

	printf("hello printf");
	fprintf(stdout, "hello fprintf");
	fwrite(fstr, strlen(fstr), 1, stdout);
	// 去掉\n
	// close(1);
	return 0;
}

int main4()
{
	// const char *fstr = "hello fwrite";
	const char *str = "hello write";

	// printf("hello printf");
	// fprintf(stdout, "hello fprintf");
	// fwrite(fstr, strlen(fstr), 1, stdout);
	// 去掉\n
	write(1, str, strlen(str));
	close(1);
	return 0;
}

int main5()
{
	printf("hello printf");
	return 0;
}

int main()
{
	const char *fstr = "hello fwrite\n";
	const char *str = "hello write\n";

	printf("hello printf\n");
	sleep(2);
	fprintf(stdout, "hello fprintf\n");
	sleep(2);
	fwrite(fstr, strlen(fstr), 1, stdout);
	sleep(2);

	write(1, str, strlen(str));
	sleep(5);
	return 0;
}