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
