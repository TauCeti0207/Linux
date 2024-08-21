#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void show()
{
	printf("hello world\n");
	printf("hello world\n");
	printf("hello world\n");
	// exit(13);
	_exit(14);
	printf("hello world\n");
}
int main()
{
	show();
	printf("hello world\n");
	return 12;
}
