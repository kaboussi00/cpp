#include "HumanA.hpp"

HumanA::HumanA(std::string nameHumanA, Weapon &type) : type(type), name(nameHumanA){}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << type.getType() << std::endl;
}