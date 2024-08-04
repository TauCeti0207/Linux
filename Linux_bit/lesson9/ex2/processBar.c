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
	// NONE表示关闭颜色输出
	printf(GREEN "%-100s" ANSI_COLOR_RED "[%d%%]" ANSI_COLOR_BLUE "[%c]\r" NONE, bar, rate, lable[rate % len]);
	fflush(stdout);
	bar[rate++] = STYLE; // 使用绿色色块;
	if (rate < 100)
		bar[rate] = RIGHT;
}

void initbar()
{
	memset(bar, '\0', sizeof(bar));
}