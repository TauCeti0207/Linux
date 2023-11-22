#include <iostream>
#include <cstdlib>

#define BOOL_OK 1

class Base;
class Derived;
class Component;

class Base
{
public:
    Base();
    virtual ~Base();
};

inline Base::Base()
{
    std::cout << "Class Base Constructor Executed." << std::endl;
}

inline Base::~Base()
{
    std::cout << "Class Base De-constructor Executed." << std::endl;
}

class Component
{
public:
    Component();
    ~Component();
};

inline Component::Component()
{
    std::cout << "Class Component Constructor Executed." << std::endl;
}

inline Component::~Component()
{
    std::cout << "Class Component De-Constructor Executed." << std::endl;
}

class Derived : public Base
{
public:
    Derived();
    ~Derived();
    Component *comp1 = new Component;
};

inline Derived::Derived()
{
    std::cout << "Class Derived Constructor Executed." << std::endl;
}

inline Derived::~Derived()
{
    std::cout << "Class Derived De-constructor Executed." << std::endl;
    comp1->~Component();
}

int main(int argc, const char *argv[])
{
    Derived d1;
    return EXIT_SUCCESS;
}
