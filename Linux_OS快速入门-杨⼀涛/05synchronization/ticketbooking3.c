/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-12 23:42:55
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-12 23:47:24
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int ticketAmout = 2; // 票的数量: 全局变量
sem_t mutex;		 // 定义信号量mutex

/**
 * ticketAgent 函数模拟了一个售票员的行为，负责售票。
 * 它通过信号量mutex来控制对票务资源的互斥访问。
 *
 * 参数:
 *   arg - 传递给线程的参数，本例中未使用。
 * 返回值:
 *   void * - 线程退出时返回NULL。
 */
void *ticketAgent(void *arg)
{
	// 执行P操作，申请访问资源的权限。确保每次只能有一个售票员售票。
	sem_wait(&mutex);

	// 读取当前票务资源的剩余票数。
	int t = ticketAmout;

	// 检查是否有余票可售。
	if (t > 0)
	{
		printf("One ticket sold\n");
		t--;
	}
	else
	{
		printf("Ticket sold out\n");
	}

	// 更新票务资源的剩余票数。
	ticketAmout = t;

	// 执行V操作，释放资源访问权限，允许其他售票员介入。
	sem_post(&mutex);

	// 线程结束执行，返回NULL。
	pthread_exit(0);
}

int main(int argc, char const *agrv[])
{

	pthread_t ticketAgent_tid[2];
	// 参数2：这个参数决定了信号量是进程间共享还是线程间共享。
	// 如果 pshared 为 0，信号量是线程间共享的，即它只能在同一个进程中的线程之间使用。
	// 如果 pshared 非 0，信号量是进程间共享的，即它可以在不同进程之间使用。这通常需要使用命名信号量，并且操作系统会负责同步不同进程之间的访问。
	// 参数3：这个参数设置了信号量的初始值。
	sem_init(&mutex, 0, 1); // 初始化信号量

	for (int i = 0; i < 2; i++)
	{
		pthread_create(ticketAgent_tid + i, NULL, ticketAgent, NULL);
	}

	for (int i = 0; i < 2; i++)
	{
		pthread_join(ticketAgent_tid[i], NULL);
	}

	sleep(1);
	printf("The left ticket is %d\n", ticketAmout);

	sem_destroy(&mutex); // 销毁信号量

	return 0;
}