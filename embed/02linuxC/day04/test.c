#include <stdio.h>

void fun()
{
	int i = 0;
	for(i = 0; i < 3; ++i)
	{
		printf("i am fun\n");
	}
}

int main(int argc, const char* argv[])
{
	for(int i = 0; i < 5; ++i)
	{
		printf("*******\n");
	}
	printf("hello world\n");
	fun();
	return 0;
}
