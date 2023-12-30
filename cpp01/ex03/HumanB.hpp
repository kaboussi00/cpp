#pragma once

#include "Weapon.hpp"

class HumanB{
private:
    Weapon *type;
    std::string name;
public:

    HumanB(std::string nameHumanB);
    void attack();
    void setWeapon(Weapon &typeHumanB);
};
