/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-13 15:00:51
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-13 16:07:54
 */
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

sem_t d, c;
#define NUM_ITERATIONS 5
void *Driver(void *arg)
{
	for (int i = 0; i < NUM_ITERATIONS; i++)
	{
		sem_wait(&d); // P(d)
		printf("开车\n");
		printf("正常行车\n");
		printf("到站停车\n");
		sem_post(&c); // V(c)
	}
	pthread_exit(0);
}

void *Conductor(void *arg)
{
	for (int i = 0; i < NUM_ITERATIONS; i++)
	{
		printf("关车门\n");
		sem_post(&d); // V(d)
		printf("售票\n");
		sem_wait(&c); // P(c)
		printf("开车门\n");
	}
	pthread_exit(0);
}

int main()
{
	pthread_t driver_thread, conductor_thread;

	// 初始化信号量
	sem_init(&d, 0, 0);
	sem_init(&c, 0, 0);

	// 创建线程
	pthread_create(&driver_thread, NULL, Driver, NULL);
	pthread_create(&conductor_thread, NULL, Conductor, NULL);

	// 等待线程结束
	pthread_join(driver_thread, NULL);
	pthread_join(conductor_thread, NULL);

	// 销毁信号量
	sem_destroy(&d);
	sem_destroy(&c);

	return 0;
}