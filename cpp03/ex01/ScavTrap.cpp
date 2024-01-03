#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
    std::cout<< "⚔️ ScavTrap : default constructor called!"<<std::endl;
     name = "";
     hit = 100;
     energy = 50;
     attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    std::cout << " ⚔️ ScavTrap : constructor with param called!"<< std::endl;
    this->name = name;
    hit = 100;
    energy = 50;
    attackDamage = 20; 
}

ScavTrap::~ScavTrap() {
    std::cout << "⚔️ scavTrap : deconstructor called!"<< std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj){
    std::cout<<"⚔️ scavTrap : assignement constructor called!" << std::endl;
    if (this != &obj)
    {
        this->name = obj.name;
        this->hit = obj.hit;
        this->energy = obj.energy;
        this->attackDamage = obj.attackDamage;
    }
    return(*this);
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj){
    std::cout<< "⚔️ ScavTrap : copy constructor scav called !" << std::endl;
    *this = obj;
}

void ScavTrap::attack(const std::string& target) {
		if (hit == 0 || energy == 0)
			std::cout << "⚔️ ScavTrap : no energy or hit left!" << std::endl;
		else
		{
			std::cout << "⚔️ ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!"<< std::endl; 
			energy-=1;
		}
}

void ScavTrap::guardGate(){
    std::cout << "⚔️ ScavTrap is now in Gate keeper mode!" << std::endl;
}
