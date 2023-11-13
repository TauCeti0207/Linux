#include "Solider.h"

Solider::Solider(std::string name)
{
    this->_name = name;
    this->_prt_gun = nullptr;
}

Solider::~Solider()
{
    if (this->_prt_gun == nullptr)
    {
        return;
    }
    delete this->_prt_gun;
    this->_prt_gun = nullptr;
}

void Solider::addGun(Gun *ptr_gun)
{
    this->_prt_gun = ptr_gun;
}

void Solider::addBulletToGun(int num)
{
    this->_prt_gun->addBullet(num);
}

bool Solider::fire()
{
    return (this->_prt_gun->shoot());
}
