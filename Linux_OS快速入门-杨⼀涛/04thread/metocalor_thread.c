/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-11 16:00:37
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-11 16:02:54
 */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

// 计算圆周率的函数
void *calculate_pi(void *args)
{
	// 初始化随机数种子
	unsigned int seed = time(NULL);
	// 圆内点数
	int circle_points = 0;
	// 正方形内点数
	int square_points = 0;
	// 采样间隔数，由传入的参数获得
	int intervals = *((int *)args);

	// 蒙特卡洛方法计算圆周率
	for (int i = 0; i < intervals * intervals; ++i)
	{
		// 生成0到1之间的随机x坐标
		double rand_x = (double)rand_r(&seed) / RAND_MAX;
		// 生成0到1之间的随机y坐标
		double rand_y = (double)rand_r(&seed) / RAND_MAX;

		// 判断随机点是否在单位圆内
		if ((rand_x * rand_x) + (rand_y * rand_y) <= 1)
		{
			// 如果在圆内，增加圆内点数
			circle_points++;
		}
		// 增加正方形内点数
		square_points++;
	}

	// 根据蒙特卡洛方法计算圆周率
	double pi = (double)(4.0 * circle_points) / square_points;
	// 输出计算结果
	printf("The estimated PI is %lf in %d times\n", pi, intervals * intervals);

	// 线程退出 0表示正常返回
	pthread_exit(0);
}

int main()
{
	// 记录程序开始时间和计算所用时间
	clock_t start, deleta;
	double time_used;
	start = clock();

	// 创建10个线程用于计算pi
	pthread_t calculate_pi_threads[10];

	// 为每个线程准备计算任务的参数
	int args[10];

	// 初始化线程和参数，并启动线程
	for (int i = 0; i < 10; ++i)
	{
		args[i] = 1000 * (i + 1);
		pthread_create(calculate_pi_threads + i, NULL, calculate_pi, args + i);
	}

	// 等待所有线程执行完毕
	for (int i = 0; i < 10; ++i)
	{
		pthread_join(calculate_pi_threads[i], NULL);
	}

	// 计算程序总运行时间
	deleta = clock() - start;
	printf("The time taken in total: %lf seconds\n", (double)deleta / CLOCKS_PER_SEC);

	return 0;
}