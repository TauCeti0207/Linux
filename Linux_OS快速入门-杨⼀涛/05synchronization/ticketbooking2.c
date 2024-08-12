/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-12 23:06:20
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-12 23:11:49
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int ticketAmout = 2; // 票的数量: 全局变量
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *ticketAgent(void *arg)
{
	int *ticketId = (int *)arg;
	// 上锁
	pthread_mutex_lock(&lock);

	int t = ticketAmout;
	if (t > 0)
	{
		printf("Ticket agent %d: one ticket sold!\n", *ticketId);
		t--;
	}
	else
	{
		printf("Ticket agent %d: Ticket sold out!\n", *ticketId);
	}

	ticketAmout = t;

	// 解锁
	pthread_mutex_unlock(&lock);

	pthread_exit(0);
}

int main(int argc, char const *agrv[])
{

	pthread_t ticketAgent_tid[2];

	int ticketIds[2] = {1, 2};

	for (int i = 0; i < 2; i++)
	{
		pthread_create(ticketAgent_tid + i, NULL, ticketAgent, &ticketIds[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		pthread_join(ticketAgent_tid[i], NULL);
	}

	sleep(1);
	printf("The left ticket is %d\n", ticketAmout);

	return 0;
}