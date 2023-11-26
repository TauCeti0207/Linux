//  main.cpp
//  C++NewDeleteOverload

#include <iostream>
#include <cstdlib>

class Foo
{
public:
    int _id;
    long _data;
    std::string _str;
    Foo() : _id(0)
    {
        std::cout << "default ctor.this = " << this << " id = " << _id << std::endl;
    }
    Foo(int i) : _id(i)
    {
        std::cout << "ctor.this = " << this << " id = " << _id << std::endl;
    }
    ~Foo()
    {
        std::cout << "dtor.this = " << this << " id = " << _id << std::endl;
    }

    static void *operator new(size_t size);
    static void operator delete(void *pdead, size_t size);
    static void *operator new[](size_t size);
    static void operator delete[](void *pdead, size_t size);
};

void *Foo::operator new(size_t size)
{
    Foo *p = (Foo *)malloc(size);
    std::cout << "Foo::operator new(), size = " << size << "\t return: " << p << std::endl;
    return p;
}

void Foo::operator delete(void *pdead, size_t size)
{
    std::cout << "Foo::operator delete(), pdead = " << pdead << " size = " << size << std::endl;
    free(pdead);
}

void *Foo::operator new[](size_t size)
{
    Foo *p = (Foo *)malloc(size);
    std::cout << "Foo::operator new[](), size = " << size << "\t return: " << p << std::endl;
    return p;
}

void Foo::operator delete[](void *pdead, size_t size)
{
    std::cout << "Foo::operator delete[](), pdead = " << pdead << " size = " << size << std::endl;
    free(pdead);
}

int main(int argc, const char *argv[])
{
    std::cout << sizeof(int) << " " << sizeof(long) << " " << sizeof(std::string) << " " << sizeof(int *) << std::endl;
    Foo *pf = new Foo;                                          // 若无成员new函数则调用全局new函数
    std::cout << "sizeof(pf) is " << sizeof(pf) << std::endl;   // 8
    delete pf;                                                  // 若无成员delete函数则调用全局delete函数
    Foo *pfa = ::new Foo;                                       // 强制采用全局new函数
    std::cout << "sizeof(pfa) is " << sizeof(pfa) << std::endl; // 8
    ::delete pfa;                                               // 强制采用全局delete函数
    std::cout << "sizeof(Foo) = " << sizeof(Foo) << std::endl;
    Foo *p = new Foo(7);
    delete p;
    Foo *pArray = new Foo[5]; // 会调用5次构造
    delete[] pArray;

    Foo *pglobal = ::new Foo(7);
    ::delete p;
    Foo *pArrayglobal = ::new Foo[5];
    ::delete[] pArray;
    return EXIT_SUCCESS;
}
