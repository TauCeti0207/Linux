#pragma once
#include <iostream>

class myswap
{
private:
    int _a;
    int _b;

public:
    myswap(int a, int b)
    {
        this->_a = a;
        this->_b = b;
    }
    void run();
    void printInfo();
};
