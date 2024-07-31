#include "processBar.h"
#include <unistd.h>
#include <string.h>

const char *lable = "|/-\\";
char bar[NUM];

// v2: 是如何被调用的
void processbar(int rate)
{
	if (rate < 0 || rate > 100)
		return;

	int len = strlen(lable);
	printf(GREEN "[%-100s]" NONE "[%d%%][%c]\r", bar, rate, lable[rate % len]); // 没有\n,就没有立即刷新，因为显示器模式是行刷新
	fflush(stdout);
	bar[rate++] = STYLE;
	if (rate < 100)
		bar[rate] = RIGHT;
}

void initbar()
{
	memset(bar, '\0', sizeof(bar));
}