// #include <stdio.h>

// // 函数的参数的存储，从右到左一次入栈
// void print(int a, ...)
// {
// 	int *ptr = &a;
// 	printf("%d ", *ptr);
// 	printf("%d ", *(ptr + 1));
// 	printf("%d ", *(ptr + 2));
// }

// int main()
// {
// 	print(1, 2, 3);
// 	// printf("%d %s", 1, "aaaa"); // C语言的可变参数列表
// 	return 0;
// }
// #include <stdio.h>

// // 把省略的参数用...代替
// // 注意退出时机: 1. 在最后面加一个退出标识
// // 2. 第一个参数是必须指定的, 所以, 可以把第一个参数设置为参数的个数
// void print(int a, ...)
// {
// 	int *ptr = &a;
// 	for (int i = 1; i < *ptr; i++)
// 	{
// 		printf("%d ", *(ptr + i));
// 	}
// }

// int main()
// {
// 	print(9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
// 	// printf("%d %s", 1, "aaaa"); // C语言的可变参数列表
// 	return 0;
// }

#include <stdio.h>
#include <stdarg.h>

void print_var_args(int count, ...)
{
	va_list args;
	va_start(args, count); // 初始化args指向第一个可变参数

	for (int i = 0; i < count; ++i)
	{
		printf("%d ", va_arg(args, int)); // 获取下一个参数
	}

	va_end(args); // 清理可变参数列表
}

int main()
{
	print_var_args(3, 1, 2, 3);
	return 0;
}
