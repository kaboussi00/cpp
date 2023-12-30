#include "HumanB.hpp"

HumanB::HumanB(std::string nameHumanB)
{
    type = NULL;
    name = nameHumanB;
}

void HumanB::setWeapon(Weapon &typeHumanB)
{
   type = &typeHumanB;
}

void HumanB::attack()
{
   if (type)
      std::cout << name << " attacks with their " << type->getType() << std::endl;
   else
      std::cout << name << " attacks with bare hands" << std::endl;
}