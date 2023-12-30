#include "Weapon.hpp"

Weapon::Weapon(std::string weapontype)
{
    type = weapontype;
}

const std::string &Weapon::getType()
{
    return type;
}

void Weapon::setType(std::string newtype)
{
    type = newtype;
}