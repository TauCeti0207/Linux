#include <iostream>
#include <thread>
#include <mutex>

int globalVar = 0;
std::mutex mtx1;
std::mutex mtx2;
void task1()
{
    for (size_t i = 0; i < 100000; i++)
    {
        // 这也被称为RAII
        std::lock_guard<std::mutex> lock1(mtx1); // 构造函数中自动上锁 析构函数自动解锁
        std::lock_guard<std::mutex> lock2(mtx2);

        // std::unique_lock<std::mutex> lock3(mtx1); // unique_lock比lock_guard更加灵活
        // 可以中途解锁
        //  lock3.unlock();

        globalVar++;
        globalVar--;

        // 利用lock_guard可以避免如下的情况
        /* callAFUNC(){ throw ...}
            if(xxx) return;
        */
    }
}

void task2()
{
    for (size_t i = 0; i < 100000; i++)
    {
        // 如果要对多个互斥量上锁，用标准库中的lock会更好
        // 解决可能因为上锁顺序不同产生的死锁
        std::lock(mtx1, mtx2);
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