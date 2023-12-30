#pragma once

#include "Weapon.hpp"

class HumanA{
    private:

    Weapon &type;
    std::string name;

public:

    HumanA(std::string nameHumanA, Weapon &type);
    void attack();
};