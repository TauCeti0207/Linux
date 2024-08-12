#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h> // 添加对pause()函数的包含

#define handle_error_en(en, msg) \
	do                           \
	{                            \
		errno = en;              \
		perror(msg);             \
		exit(EXIT_FAILURE);      \
	} while (0)

/**
 * 打印pthread属性
 *
 * 该函数接收一个pthread属性对象指针和一个前缀字符串，通过调用一系列的pthread属性获取函数，
 * 获取并打印出线程的detach状态、作用域、调度策略、调度参数以及栈地址和大小等信息。
 *
 * @param attr pthread属性对象指针，用于获取属性信息
 * @param prefix 打印信息前缀，用于格式化输出
 */
static void display_pthread_attr(pthread_attr_t *attr, char *prefix)
{
	int s, i;
	size_t v;
	void *stkaddr;
	struct sched_param sp;

	// 获取线程detach状态
	s = pthread_attr_getdetachstate(attr, &i);
	if (s != 0)
		handle_error_en(s, "pthread_attr_getdetachstate");
	printf("%sDetach state = %s\n", prefix, (i == PTHREAD_CREATE_DETACHED) ? "PTHREAD_CREATE_DETACHED" : (i == PTHREAD_CREATE_JOINABLE) ? "PTHREAD_CREATE_JOINABLE"
																																		: "???");

	// 获取线程作用域
	s = pthread_attr_getscope(attr, &i);
	if (s != 0)
		handle_error_en(s, "pthread_attr_getscope");
	printf("%sScope = %s\n", prefix, (i == PTHREAD_SCOPE_SYSTEM) ? "PTHREAD_SCOPE_SYSTEM" : (i == PTHREAD_SCOPE_PROCESS) ? "PTHREAD_SCOPE_PROCESS"
																														 : "???");

	// 获取线程继承调度属性
	s = pthread_attr_getinheritsched(attr, &i);
	if (s != 0)
		handle_error_en(s, "pthread_attr_getinheritsched");
	printf("%sInherit scheduler = %s\n", prefix, (i == PTHREAD_INHERIT_SCHED) ? "PTHREAD_INHERIT_SCHED" : (i == PTHREAD_EXPLICIT_SCHED) ? "PTHREAD_EXPLICIT_SCHED"
																																		: "???");

	// 获取线程调度策略
	s = pthread_attr_getschedpolicy(attr, &i);
	if (s != 0)
		handle_error_en(s, "pthread_attr_getschedpolicy");
	printf("%sSched policy = %s\n", prefix, (i == SCHED_FIFO) ? "SCHED_FIFO" : (i == SCHED_RR) ? "SCHED_RR"
																							   : "???");

	// 获取线程调度参数
	s = pthread_attr_getschedparam(attr, &sp);
	if (s != 0)
		handle_error_en(s, "pthread_attr_getschedparam");
	printf("%sSched param: priority = %d\n", prefix, sp.sched_priority);

	// 获取线程栈地址和大小
	s = pthread_attr_getstack(attr, &stkaddr, &v);
	if (s != 0)
		handle_error_en(s, "pthread_attr_getstack");
	printf("%sStack: addr = %p, size = %zu\n", prefix, stkaddr, v);
}

/*
 * computing - 线程执行函数
 *
 * 参数:
 *   void *arg - 传递给线程的参数，此处未使用
 *
 * 返回值:
 *   void * - 线程执行完毕返回值，此处未使用
 *
 * 功能:
 *   本函数演示了如何在POSIX线程（pthread）中获取线程属性并展示它们。
 *   它首先打印出线程正在运行的信息，然后尝试获取当前线程的属性。
 *   如果获取属性失败，它会打印错误信息。成功获取到属性后，它会打印出线程的属性信息，
 *   然后等待一个信号。最后，线程退出。
 */
void *computing(void *arg)
{
	int s;
	pthread_attr_t gattr;
	printf("Child thread is running...\n");
	// 这里可以添加线程要执行的代码
	s = pthread_getattr_np(pthread_self(), &gattr);
	if (s != 0)
	{
		handle_error_en(s, "pthread_getattr_np");
	}

	printf("Thread attributes:\n");
	display_pthread_attr(&gattr, "\t"); // 添加一个空字符串作为前缀参数

	pause(); // Wait for a signal

	pthread_exit(NULL); // called when thread terminated
}

int main()
{
	pthread_t tid;		 // 线程ID
	pthread_attr_t attr; // 线程属性

	// 初始化线程属性为默认值
	pthread_attr_init(&attr);

	// 创建线程
	pthread_create(&tid, &attr, computing, NULL);

	// 主线程什么都不做
	printf("Master thread doing nothing...\n");

	// 等待指定的线程结束
	pthread_join(tid, NULL);

	printf("Thread %ld has ended.\n", tid);

	return 0;
}