/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-13 14:47:20
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-13 14:47:21
 */
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_ITERATIONS 5

sem_t plate;	 /* 盘子里允许放一个水果 */
sem_t no_orange; /* 盘子里没有桔子 */
sem_t no_apple;	 /* 盘子里没有苹果 */

void *father(void *arg)
{
	for (int i = 0; i < NUM_ITERATIONS; i++)
	{
		sem_wait(&plate); /* P(sp) */
		printf("Father puts an apple on the plate.\n");
		sem_post(&no_apple); /* V(sg2) */
	}
	return NULL;
}

void *daughter(void *arg)
{
	for (int i = 0; i < NUM_ITERATIONS; i++)
	{
		sem_wait(&no_apple); /* P(sg2) */
		printf("Daughter takes an apple from the plate.\n");
		sem_post(&plate); /* V(sp) */
	}
	return NULL;
}

void *mother(void *arg)
{
	for (int i = 0; i < NUM_ITERATIONS; i++)
	{
		sem_wait(&plate); /* P(sp) */
		printf("Mother puts an orange on the plate.\n");
		sem_post(&no_orange); /* V(sg1) */
	}
	return NULL;
}

void *son(void *arg)
{
	for (int i = 0; i < NUM_ITERATIONS; i++)
	{
		sem_wait(&no_orange); /* P(sg1) */
		printf("Son takes an orange from the plate.\n");
		sem_post(&plate); /* V(sp) */
	}
	return NULL;
}

int main()
{
	pthread_t father_thread, daughter_thread, mother_thread, son_thread;

	// 初始化信号量
	sem_init(&plate, 0, 1);
	sem_init(&no_orange, 0, 0);
	sem_init(&no_apple, 0, 0);

	// 创建线程
	pthread_create(&father_thread, NULL, father, NULL);
	pthread_create(&daughter_thread, NULL, daughter, NULL);
	pthread_create(&mother_thread, NULL, mother, NULL);
	pthread_create(&son_thread, NULL, son, NULL);

	// 等待线程结束
	pthread_join(father_thread, NULL);
	pthread_join(daughter_thread, NULL);
	pthread_join(mother_thread, NULL);
	pthread_join(son_thread, NULL);

	// 销毁信号量
	sem_destroy(&plate);
	sem_destroy(&no_orange);
	sem_destroy(&no_apple);

	return 0;
}