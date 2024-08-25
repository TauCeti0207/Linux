/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-25 10:31:34
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-25 10:33:24
 */
#include <stdio.h>

#define flags_A 0x1 // 0000 0001
#define flags_B 0x2 // 0000 0010
#define flags_C 0x4 // 0000 0100
#define flags_D 0x8 // 0000 1000

void func(int f)
{
	if (f & flags_A)
		printf("hello A\n");
	if (f & flags_B)
		printf("hello B\n");
	if (f & flags_C)
		printf("hello C\n");
	if (f & flags_D)
		printf("hello D\n");
}

int main()
{
	func(flags_A | flags_B);
	func(flags_A | flags_D);
	func(flags_A);
	func(flags_C);
	return 0;
}