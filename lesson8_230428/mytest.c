/*************************************************************************
        > File Name: mytest.c
        > Author: tauceti0207
        > Mail: 2076188013@qq.com
        > Created Time: Fri Apr 28 09:08:49 2023
 ************************************************************************/

#include <stdio.h>
int AddToTop(int top)
{
  int res = 0;
  int i;
  for(i = 1; i <= top; ++i)
  {
    res += i;
  }
  return res;
}
int main()
{
  int result = 0;
  int top = 100;
  result = AddToTop(top);
  printf("result: %d\n", result);
  return 0;
}
