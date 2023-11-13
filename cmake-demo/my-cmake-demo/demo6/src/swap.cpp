#include "myswap.h"
void myswap::run()
{
    int tmp;
    tmp = _a;
    _a = _b;
    _b = tmp;
}

void myswap::printInfo()
{
    std::cout << "_a = " << _a << std::endl;
    std::cout << "_b = " << _b << std::endl;
}