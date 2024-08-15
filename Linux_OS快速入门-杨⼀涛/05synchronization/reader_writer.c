/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-13 16:31:39
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-13 16:38:58
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 2
#define NUM_ITERATIONS 2

int data = 0;
int reader_count = 0;
sem_t rw_mutex;
sem_t mutex;

// 定义读取数据的线程函数
void *reader(void *arg)
{
	// 从传入的参数中获取线程标识符
	int id = *(int *)arg;
	// while (1)
	for (int i = 0; i < NUM_ITERATIONS; i++)
	{
		// 等待互斥信号量，以确保读者计数的原子性操作
		sem_wait(&mutex);
		// 进入读区域前，读者计数加一
		reader_count++;
		// 如果是第一个读者，则获取写保护，防止写者修改数据
		if (reader_count == 1)
		{
			sem_wait(&rw_mutex);
		}
		// 释放互斥信号量，允许其他读者进入
		sem_post(&mutex);

		// 读取并输出数据
		printf("Reader %d reads data: %d\n", id, data);

		// 再次等待互斥信号量，以确保读者计数的原子性操作
		sem_wait(&mutex);
		// 离开读区域前，读者计数减一
		reader_count--;
		// 如果是最后一个离开的读者，则释放写保护，允许写者进行修改
		if (reader_count == 0)
		{
			sem_post(&rw_mutex);
		}
		// 释放互斥信号量，允许其他操作进行
		sem_post(&mutex);

		// 模拟一些延迟，以模拟实际读取操作的时间
		usleep(100000);
	}
	return NULL;
}

// The writer function is responsible for writing data
// Parameters:
//   arg: A pointer to an integer type, representing the writer's identifier
void *writer(void *arg)
{
	// Convert the passed argument to an integer type, obtaining the writer's identifier
	int id = *(int *)arg;

	// The writer continuously executes the following operations
	// while (1)
	for (int i = 0; i < NUM_ITERATIONS; i++)
	{
		// Acquire the read/write mutex, ensuring exclusive write access
		sem_wait(&rw_mutex);

		// Increment the data value, simulating a write operation
		data++;
		// Print the writer's identifier and the current data value
		printf("Writer %d writes data: %d\n", id, data);

		// Release the read/write mutex, allowing other writers to write or readers to read
		sem_post(&rw_mutex);

		// Simulate a delay, representing the time taken for writing operations
		usleep(150000);
	}
	// The thread ends, returning NULL
	return NULL;
}

// 主函数
int main()
{
	// 初始化读者线程和写者线程的线程标识符数组
	pthread_t readers[NUM_READERS];
	pthread_t writers[NUM_WRITERS];
	// 初始化读者和写者的ID数组
	int reader_ids[NUM_READERS];
	int writer_ids[NUM_WRITERS];

	// 初始化读写互斥信号量和访问共享资源的互斥信号量
	sem_init(&rw_mutex, 0, 1);
	sem_init(&mutex, 0, 1);

	// 创建读者线程
	for (int i = 0; i < NUM_READERS; i++)
	{
		reader_ids[i] = i;
		// 为每个读者线程调用pthread_create函数，传入对应的读者ID
		pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
	}

	// 创建写者线程
	for (int i = 0; i < NUM_WRITERS; i++)
	{
		writer_ids[i] = i;
		// 为每个写者线程调用pthread_create函数，传入对应的写者ID
		pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
	}

	// 等待所有读者线程结束
	for (int i = 0; i < NUM_READERS; i++)
	{
		pthread_join(readers[i], NULL);
	}

	// 等待所有写者线程结束
	for (int i = 0; i < NUM_WRITERS; i++)
	{
		pthread_join(writers[i], NULL);
	}

	// 销毁信号量
	sem_destroy(&rw_mutex);
	sem_destroy(&mutex);

	// 程序正常退出
	return 0;
}