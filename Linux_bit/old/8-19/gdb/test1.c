#include<stdio.h>

int AddToTop(int top)
{
  int res = 0;
  for(int i = 1; i <= top; ++i)
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
