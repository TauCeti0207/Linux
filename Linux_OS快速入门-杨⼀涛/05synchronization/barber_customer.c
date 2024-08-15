/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-13 16:43:58
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-13 17:30:54
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// 定义最大顾客数
#define MAX_CUSTOMERS 10
#define MAX_WAITING 3

// 定义全局变量
int waiting_customers = 0;
sem_t barber_ready;	  // 理发师准备好的信号量
sem_t customer_ready; // 顾客准备好的信号量
sem_t mutex;		  // 互斥锁，用于保护共享资源

void cut_hair()
{
	printf("Barber cuts hair.\n"); // 理发师开始理发
}
// 理发师线程函数
void *barber(void *arg)
{
	while (1)
	{
		sem_wait(&customer_ready); // 等待顾客准备好
		sem_wait(&mutex);		   // 获取互斥锁
		waiting_customers--;	   // 减少等待顾客数
		printf("理发师：等待顾客-1，还剩%d人等待 \n", waiting_customers);
		sem_post(&mutex);		 // 释放互斥锁
		cut_hair();				 // 理发ing, 这个时候顾客已经独享理发师了，所以不在临界区
		sem_post(&barber_ready); // 剪完头发，理发师准备好
	}
	pthread_exit(NULL);
	return NULL;
}

// 顾客线程函数
void *customer(void *arg)
{
	int id = *(int *)arg;

	sem_wait(&mutex); // 获取互斥锁
	if (waiting_customers < MAX_WAITING)
	{							   // 如果等待顾客数小于最大顾客数
		waiting_customers++;	   // 增加等待顾客数
		sem_post(&mutex);		   // 释放互斥锁
		sem_wait(&barber_ready);   // 等待理发师 p
		sem_post(&customer_ready); // 顾客准备好 多了一个顾客在等待

		printf("Customer %d get haricut.\n", id);
	}
	else
	{
		sem_post(&mutex);							// 释放互斥锁
		printf("没椅子了，Customer %d 离开\n", id); // 顾客离开
	}

	// 模拟一些延迟
	usleep(100000);
	pthread_exit(NULL);
	return NULL;
}

int main()
{
	pthread_t barbers[1];
	pthread_t customers[MAX_CUSTOMERS];
	int customer_ids[MAX_CUSTOMERS];

	// 初始化信号量和互斥锁
	sem_init(&barber_ready, 0, 1);
	sem_init(&customer_ready, 0, 0);
	sem_init(&mutex, 0, 1);

	// 创建理发师线程
	pthread_create(&barbers[0], NULL, barber, NULL);

	// 创建顾客线程
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		customer_ids[i] = i;
		pthread_create(&customers[i], NULL, customer, &customer_ids[i]);
	}

	// 等待所有顾客线程结束
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		pthread_join(customers[i], NULL);
	}

	// 销毁信号量和互斥锁
	sem_destroy(&barber_ready);
	sem_destroy(&customer_ready);
	sem_destroy(&mutex);

	return 0;
}