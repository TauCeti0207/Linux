/*************************************************************************
        > File Name: mytest.c
        > Author: tauceti0207
        > Mail: 2076188013@qq.com
        > Created Time: Fri Apr 28 23:14:17 2023
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
  pid_t id = fork();
  printf("hello world! id: %d\n", id);
  sleep(1);
  return 0;
}
