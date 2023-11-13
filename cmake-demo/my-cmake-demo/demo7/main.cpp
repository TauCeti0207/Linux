#include "Gun.h"
#include "Solider.h"
#include <iostream>

void test()
{
    Solider sanduo("xusanduo");
    sanduo.addGun(new Gun("AK47"));
    sanduo.addBulletToGun(20);
    sanduo.fire();
}

int main(int argc, char const *argv[])
{
    // std::cout << "test pretask" << std::endl;
    test();
    return 0;
}
