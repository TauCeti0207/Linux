/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-13 14:30:05
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-13 14:32:01
 */
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5

typedef struct
{
	int buffer[BUFFER_SIZE];
} BoundedBuffer;

BoundedBuffer B;
sem_t empty;
sem_t full;
sem_t mutex;
int in = 0, out = 0;

void *producer(void *arg)
{
	int product;
	while (1)
	{
		// 生产一个产品
		product = rand() % 100 + 1;

		// 等待空闲缓冲区 P操作
		sem_wait(&empty);

		// 获取互斥锁
		sem_wait(&mutex);

		// 将产品放入缓冲区
		B.buffer[in] = product;
		printf("Producer: Produced item %d at index %d\n", product, in);
		in = (in + 1) % BUFFER_SIZE;

		// 释放互斥锁
		sem_post(&mutex);

		// 增加满缓冲区计数 V操作
		sem_post(&full);

		// 模拟生产时间
		usleep(100000);
	}
}

void *consumer(void *arg)
{
	int product;
	while (1)
	{
		// 等待满缓冲区
		sem_wait(&full);

		// 获取互斥锁
		sem_wait(&mutex);

		// 从缓冲区取出产品
		product = B.buffer[out];
		printf("Consumer: Consumed item %d from index %d\n", product, out);
		out = (out + 1) % BUFFER_SIZE;

		// 释放互斥锁
		sem_post(&mutex);

		// 增加空闲缓冲区计数
		sem_post(&empty);

		// 模拟消费时间
		usleep(150000);
	}
}

int main()
{
	pthread_t producer_thread, consumer_thread;

	// 初始化信号量
	sem_init(&empty, 0, BUFFER_SIZE);
	sem_init(&full, 0, 0);
	sem_init(&mutex, 0, 1);

	// 创建生产者和消费者线程
	pthread_create(&producer_thread, NULL, producer, NULL);
	pthread_create(&consumer_thread, NULL, consumer, NULL);

	// 等待线程结束
	pthread_join(producer_thread, NULL);
	pthread_join(consumer_thread, NULL);

	// 销毁信号量
	sem_destroy(&empty);
	sem_destroy(&full);
	sem_destroy(&mutex);

	return 0;
}