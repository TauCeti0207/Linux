/*************************************************************************
        > File Name: hello2.c
        > Author: tauceti0207
        > Mail: 2076188013@qq.com
        > Created Time: Wed Apr 26 23:07:17 2023
 ************************************************************************/

#include <stdio.h>
#define M 10
int main()
{
  printf("hello C!\n");
  printf("M:%d\n", M);
  printf("hello C1\n");
 // printf("hello C2\n");
 // printf("hello C3\n");
 // printf("hello C5\n");
  printf("hello C5\n");

#ifdef DEBUG 
  printf("hello debug\n");
#else
  printf("hello release\n");
#endif 
  return 0;
}
