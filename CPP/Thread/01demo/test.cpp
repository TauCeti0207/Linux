#include <iostream>
#include <thread>
#include <chrono>
// 线程入口函数
void ThreadMain()
{
    std::cout << "进入子线程 id:" << std::this_thread::get_id() << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "in thread id = " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 线程释放cpu资源1秒
    }
}

void test_thread()
{
    std::cout << "主线程ID " << std::this_thread::get_id() << std::endl;
    // 1 创建并启动子线程，进入线程函数
    std::thread th(ThreadMain);
    std::cout << "等待子线程退出" << std::endl;
    th.join();
    std::cout << "等待子线程返回" << std::endl;
}

// 主线程入口
int main(int argc, char *argv[])
{
    test_thread();
    return 0;
}