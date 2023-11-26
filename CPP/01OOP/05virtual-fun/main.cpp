#include <iostream>
#include <cstdlib>

class A
{
public:
    virtual void vfunc1() const
    {
        std::cout << "classA vfunc1 called." << std::endl;
    }
};

class B : public A
{
public:
    void vfunc1() const
    {
        std::cout << "classB vfunc1 called." << std::endl;
    }
};

class C : public B
{
};

int main(int argc, const char *argv[])
{
    B b;
    A a = (A)b;
    a.vfunc1();

    A *pa = new B;
    pa->vfunc1();

    pa = &b;
    pa->vfunc1();
    return EXIT_SUCCESS;
}