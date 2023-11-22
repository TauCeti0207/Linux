#include <iostream>

// Fraction.h
class Fraction // 分数
{
public:
    Fraction(int num, int den = 1)
        : m_numerator(num), m_denominator(den) {}
    operator double() const
    {
        // return (double)(m_numerator / m_denominator); //整数除法会产生截断
        return static_cast<double>(m_numerator) / m_denominator;
        // static_cast 是 C++ 中的一种类型转换运算符，用于在编译时执行类型转换。它提供了一种安全的类型转换方式，可以在不需要执行运行时类型检查的情况下转换类型。
    }

private:
    int m_numerator;   // 分子
    int m_denominator; // 分母
};

// main.cpp
int main()
{
    Fraction f(3, 5);
    double d = 4 + f;            // corrcet 调用operator double()将f转换为0.6
    std::cout << d << std::endl; // 4，6
    return 0;
}