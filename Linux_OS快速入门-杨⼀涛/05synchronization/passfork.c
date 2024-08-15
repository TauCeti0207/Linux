/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-12 23:48:46
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-12 23:53:46
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t road;

/*
 * 函数名：cars
 * 功能：模拟汽车通过叉路口的行为
 * 参数：argc - 传递给线程的参数，本例中未使用
 * 返回值：void * - 线程结束时的返回值，本例中未使用
 */
void *cars(void *argc)
{
	// 输出当前线程ID，并声明即将通过叉路口的意图
	printf("(%lu) I INTEND to pass the fork\n", pthread_self());
	sleep(1);

	// 对道路信号量执行P操作，申请通过叉路口
	sem_wait(&road);

	// 输出当前线程ID，宣布已到达叉路口
	printf("(%lu) I am AT the fork\n", pthread_self());
	sleep(1);

	// 输出当前线程ID，宣布已通过叉路口
	printf("(%lu) I have PASSED the fork\n", pthread_self());
	sleep(1);

	// 对道路信号量执行V操作，释放叉路口通行权
	sem_post(&road);

	// 结束线程
	pthread_exit(0);
}

// 主函数，模拟一个有多个车辆通过的单行道
int main(int argc, char const *argv[])
{
	// 创建一个线程数组，用于模拟5辆车
	pthread_t tid[5];

	// 初始化一个信号量，用于控制通过单行道的车辆数量，初始值为2表示最多两辆车同时通过
	sem_init(&road, 0, 2);

	// 创建5个线程，每个线程代表一辆车，它们将尝试通过单行道
	for (int i = 0; i < 5; i++)
	{
		pthread_create(tid + i, NULL, cars, NULL);
		// 创建线程的详细说明请参阅pthread_create函数文档
		// 这里无需传递额外参数给线程，因此第三个参数为NULL
	}

	// 等待所有线程执行完毕，这样可以确保所有车辆都通过了单行道
	for (int i = 0; i < 5; i++)
	{
		pthread_join(tid[i], NULL);
		// pthread_join函数的详细说明请参阅pthread_join函数文档
		// 这里不需要获取线程退出状态，因此第二个参数为NULL
	}

	// 销毁信号量，这是对资源进行清理的一个步骤
	sem_destroy(&road);

	// 程序正常退出，返回值为0
	return 0;
}