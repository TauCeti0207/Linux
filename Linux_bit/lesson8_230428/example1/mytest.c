/*************************************************************************
        > File Name: mytest.c
        > Author: tauceti0207
        > Mail: 2076188013@qq.com
        > Created Time: Fri Apr 28 13:06:57 2023
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
int main()
{
  printf("hello Linux");
  fflush(stdout);//立刻刷新出来
  sleep(2);
  return 0;
}
