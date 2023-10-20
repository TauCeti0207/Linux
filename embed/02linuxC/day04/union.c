#include <stdio.h>
#include <string.h>
#define N 32

union gy
{
	int a;
	char b;
};

int main(int argc, const char *argv[])
{
	union gy n;
	n.a = 0x12345678;
	printf("%#x\n",n.a);
	printf("%ld\n",sizeof(union gy));//共用4个字节空间
	printf("%#x\n",n.b);

	//修改b a也会改变
	n.b = 'a';
	printf("%#x\n",n.a);
	printf("%#x\n",n.b);

	return 0;
}
