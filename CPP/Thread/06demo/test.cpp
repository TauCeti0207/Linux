#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

std::atomic<int> globalVar = 0; // 对要竞争的资源原子化 就可以起到线程安全 底层也是自动加锁解锁
// int globalVar = 0;
std::mutex mtx1;
std::mutex mtx2;
void task1()
{
    for (size_t i = 0; i < 100000; i++)
    {

        globalVar++;
        globalVar--;
    }
}

// 主线程入口
int main(int argc, char *argv[])
{
    std::thread t1(task1);
    std::thread t2(task1);

    t1.join();
    t2.join();

    std::cout << "current globalVar is:" << globalVar << std::endl;
    std::cout << "hardware_concurrency is:" << t1.hardware_concurrency() << std::endl; // 2core 2线程
    std::cout << "thread id is:" << std::this_thread::get_id() << std::endl;
    return 0;
}