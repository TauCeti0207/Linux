/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-11 15:40:12
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-11 15:43:14
 */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

int value = 100; // shared data section belongs to process

void *hello(void *args)
{
	for (int i = 0; i < 5; i++)
	{
		printf("hello(%d)\n", value++);
		sleep(1);
	}
	return NULL;
}

void *world(void *args)
{
	for (int i = 0; i < 5; i++)
	{
		printf("world(%d)\n", value++);
		sleep(2);
	}
	return NULL;
}

int main()
{

	srand(time(NULL));
	pthread_t tid, tid2;

	// 线程创建函数
	pthread_create(&tid, NULL, hello, NULL);
	pthread_create(&tid2, NULL, world, NULL);

	// 等待指定的线程结束
	pthread_join(tid, NULL);
	pthread_join(tid2, NULL);

	printf("In Main Thread(%d)\n", value);
	return 0;
}