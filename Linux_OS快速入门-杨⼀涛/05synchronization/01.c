/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-12 16:03:51
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-12 23:07:24
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_TICKETS 2

int ticketAmount = NUM_TICKETS;

void *ticketAgent(void *arg)
{
	int *ticketId = (int *)arg;
	while (1)
	{
		if (ticketAmount > 0)
		{
			printf("Ticket agent %d: one ticket sold!\n", *ticketId);
			ticketAmount--;
		}
		else
		{
			printf("Ticket agent %d: Ticket sold out!\n", *ticketId);
			pthread_exit(NULL);
		}
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	pthread_t ticketAgent_tid[2];

	int ticketIds[2] = {1, 2};

	for (int i = 0; i < 2; ++i)
	{
		// 第一个参数：指向新线程标识符的指针
		// 第二个参数：线程属性，这里设置为NULL，表示使用默认属性
		// 第三个参数：线程函数的地址，这里是ticketAgent函数
		// 第四个参数：传递给线程函数的参数，这里是ticketIds[i]，表示售票代理的ID
		pthread_create(&ticketAgent_tid[i], NULL, ticketAgent, &ticketIds[i]);
	}

	for (int i = 0; i < 2; ++i)
	{
		pthread_join(ticketAgent_tid[i], NULL);
	}

	printf("The left ticket is %d\n", ticketAmount);

	return 0;
}