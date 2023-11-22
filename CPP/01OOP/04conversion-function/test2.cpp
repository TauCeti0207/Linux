#include <iostream>
#include <cstdlib>

class Fraction
{
public:
    Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}
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
    Fraction d2 = f + 4;          // 调用non-explicit ctor将4转换为Fraction(4,1)后调用operator+
    std::cout << d2 << std::endl; // 23/5
    return EXIT_SUCCESS;
}