/*************************************************************************
                > File Name: process.c
                > Author: tauceti0207
                > Mail: 2076188013@qq.com
                > Created Time: Fri Apr 28 13:29:58 2023
************************************************************************/
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define NUM 101
#define STYLE '*'

void process1() {
  int cnt = 0;
  while (cnt <= 100) // 打印101次
  {
    printf("%-2d\r", cnt); // %4避免label越界 左对齐需要加上-
    fflush(stdout);
    usleep(80000);
    cnt++;
  }
}

void process() {
  char bar[NUM];
  memset(bar, '\0', sizeof(bar));
  const char *label = "|/-\\"; // \\才表示一个反斜杠
  int cnt = 0;
  while (cnt <= 100) // 打印101次
  {
    printf("loading: %-100s[%d%%] %c\r", bar, cnt,
           label[cnt % 4]); // %4避免label越界 左对齐需要加上-
    fflush(stdout);
    bar[cnt++] = STYLE;
    usleep(80000);
  }
  printf("\n"); // 跑完需换行
}

int main() {
  process1();
  return 0;
}
