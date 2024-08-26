/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-26 19:02:15
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-26 19:44:04
 */
#include "mystdio.h"
#include <unistd.h>

#define myfile "log.txt"

int main()
{
	_FILE *fp = _fopen(myfile, "a");
	if (fp == NULL)
		return 1;

	const char *msg = "hello world\n";
	int cnt = 10;
	while (cnt)
	{
		_fwrite(fp, msg, strlen(msg));
		// fflush(fp);
		sleep(1);
		cnt--;
	}

	_fclose(fp);

	return 0;
}
