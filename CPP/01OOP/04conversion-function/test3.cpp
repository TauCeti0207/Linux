#include <iostream>
#include <cstdlib>

class Fraction
{
public:
    Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
    operator double() const
    {
        // return (double)(m_numerator / m_denominator); //整数除法会产生截断
        return static_cast<double>(m_numerator) / m_denominator;
        // static_cast 是 C++ 中的一种类型转换运算符，用于在编译时执行类型转换。它提供了一种安全的类型转换方式，可以在不需要执行运行时类型检查的情况下转换类型。
    }
    Fraction operator+(const Fraction &f)
    {
        int newNumerator = m_numerator * f.m_denominator + f.m_numerator * m_denominator;
        int newDenominator = m_denominator * f.m_denominator;
        return Fraction(newNumerator, newDenominator);
    }
    // 3/5 + 4/1  --》 3/5 + 20/5 = 23/5
    // newNumerator：3*1 + 4*5 = 23
    // newDenominator: 5*1 = 5

    friend std::ostream &operator<<(std::ostream &os, const Fraction &f)
    {
        os << f.m_numerator << "/" << f.m_denominator;
        return os;
    }

private:
    int m_numerator;
    int m_denominator;
};

int main(int argc, const char *argv[])
{
    Fraction f(3, 5);
    // Fraction d2 = f + 4;
    Fraction d2 = f.operator+(4);
    std::cout << d2 << std::endl; // 23/5
    return EXIT_SUCCESS;
}