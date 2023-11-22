#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <deque>
#include <condition_variable>
std::atomic<int> globalVar = 0; // 对要竞争的资源原子化 就可以起到线程安全 底层也是自动加锁解锁
// int globalVar = 0;
std::mutex mtx;
std::mutex mtx2;
std::deque<int> q;
std::condition_variable cv;

// producer
void task1()
{
    int i = 0;
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        q.push_back(i);
        cv.notify_one(); // 每放一个数据就通知消费者队列有数据了 这里是只开了一个生产者线程一个消费者线程
        if (i < 9999999999)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
}

// consumer
void task2()
{
    int data = 0;
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        while (q.empty()) // 不能用if 如果有consumer2就会发生虚假唤醒 得用while
        {
            cv.wait(lock);
            // 相当于 lock.unlock(); cv.wait();
        }

        data = q.front();
        q.pop_front();
        std::cout << "consumer1 get value from queue:" << data << std::endl;
    }
}

// consumer2
void task3()
{
    int data = 0;
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        while (q.empty())
        {
            cv.wait(lock);
            // 相当于 lock.unlock(); cv.wait();
        }

        data = q.front();
        q.pop_front();
        std::cout << "consumer2 get value from queue:" << data << std::endl;
    }
}
// 主线程入口
int main(int argc, char *argv[])
{
    std::thread t1(task1);
    std::thread t2(task2);
    std::thread t3(task3);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "current globalVar is:" << globalVar << std::endl;
    std::cout << "hardware_concurrency is:" << t1.hardware_concurrency() << std::endl; // 2core 2线程
    std::cout << "thread id is:" << std::this_thread::get_id() << std::endl;
    return 0;
}