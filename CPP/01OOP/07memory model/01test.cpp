#include <iostream>
using namespace std;

// 全局变量
int g_a = 10;
int g_b = 20;

// const修饰的全局常量
const int c_g_a = 50;
const int c_g_b = 60;

int main()
{
    // 全局区

    // 全局变量、静态变量、常量

    // 创建普通局部变量
    int a = 30;
    int b = 40;

    cout << "局部变量a的地址为：" << reinterpret_cast<int *>(&a) << endl;
    cout << "局部变量b的地址为：" << reinterpret_cast<int *>(&b) << endl;

    cout << "全局变量g_a的地址为：" << reinterpret_cast<int *>(&g_a) << endl;
    cout << "全局变量g_b的地址为：" << reinterpret_cast<int *>(&g_b) << endl;

    // 静态变量  在普通变量前面加static,属于静态变量
    static int s_a = 10;
    static int s_b = 10;

    cout << "静态变量s_a的地址为：" << reinterpret_cast<int *>(&s_a) << endl;
    cout << "静态变量s_b的地址为：" << reinterpret_cast<int *>(&s_b) << endl;

    // 常量
    // 字符串常量
    cout << "字符串常量的地址为：" << reinterpret_cast<const int *>(&"hello world") << endl;

    // const修饰的变量
    // const修饰的局部变量,const修饰的局部变量
    cout << "全局常量c_g_a的地址为：" << reinterpret_cast<const int *>(&c_g_a) << endl;
    cout << "全局常量c_g_a的地址为：" << reinterpret_cast<const int *>(&c_g_b) << endl;

    const int c_l_a = 10; // c-const g-global  l-local;
    const int c_l_b = 10;
    cout << "局域常量c_l_a的地址为：" << reinterpret_cast<const int *>(&c_l_a) << endl;
    cout << "局域常量c_l_b的地址为：" << reinterpret_cast<const int *>(&c_l_a) << endl;

    // system("pause");

    return 0;
}