/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2024-08-11 15:48:02
 * @LastEditors: tauceti0207
 * @LastEditTime: 2024-08-11 16:07:59
 */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

/**
 * 计算圆周率的近似值。
 * 使用蒙特卡洛方法通过随机采样点来估计圆周率。
 * @param intervals 采样间隔，用于控制随机点的数量。
 */
void calculate_pi(int intervals)
{
	// 初始化随机数种子
	unsigned int seed = time(NULL);
	// 圆内的点数和正方形内的点数，用于计算圆周率
	int circle_points = 0;
	int square_points = 0;

	// 根据采样间隔生成随机点
	for (int i = 0; i < intervals * intervals; ++i)
	{
		// 生成0到1之间的随机x和y坐标
		double rand_x = (double)rand_r(&seed) / RAND_MAX;
		double rand_y = (double)rand_r(&seed) / RAND_MAX;

		// 判断随机点是否在单位圆内
		if ((rand_x * rand_x) + (rand_y * rand_y) <= 1)
		{
			circle_points++;
		}
		square_points++; // 总数
	}

	// 根据圆内点数和总点数计算圆周率
	double pi = (double)(4.0 * circle_points) / square_points;
	// 输出计算得到的圆周率近似值
	printf("The estimated PI is %lf in %d times\n", pi, intervals * intervals);
}

int main()
{

	// 记录程序开始时间
	clock_t start = clock();

	// 用于计算时间差
	double time_used;

	// 开始计算圆周率
	start = clock();

	// 使用OpenMP并行计算不同采样间隔下的圆周率
	// #pragma omp parallel for num_threads(10)
	for (int i = 0; i < 10; i++)
	{
		calculate_pi(1000 * (i + 1));
	}

	// 记录程序结束时间，计算总耗时
	double dela = clock() - start;

	// 输出总耗时
	printf("The time taken in total: %lf seconds\n", (double)dela / CLOCKS_PER_SEC);

	return 0;
}