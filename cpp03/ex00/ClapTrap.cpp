#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << " 🤖 ClapTrap : default constructor called" << std::endl;
	name="";
	hit = 10;
	energy = 10;

	attackDamage = 0;
};

ClapTrap::~ClapTrap(){
	std::cout << " 🤖 ClapTrap : destructor called" << std::endl;
};


ClapTrap::ClapTrap(std::string name){
	std::cout << " 🤖 ClapTrap : constructor with param called" << std::endl;
	this->name = name;
	hit = 10;
	energy = 10;
	attackDamage = 0;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj){
	std::cout << " 🤖 ClapTrap : assignement constructor called" << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->hit = obj.hit;
		this->energy = obj.energy;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &obj){
	std::cout << " 🤖 ClapTrap : copy constructor called" << std::endl;
	*this = obj;
}

void ClapTrap::attack(const std::string& target){
		if (hit == 0 || energy == 0)
			std::cout << " 🤖 ClapTrap : no energy or hit left!" << std::endl;
		else
		{
			std::cout << " 🤖 ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!"<< std::endl; 
			energy-=1;
		}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (hit == 0 || energy == 0)
		std::cout << " 🤖 ClapTrap : i don't have hit or energy points !"<<std::endl;
	else
	{
    std::cout<<" 🤖 ClapTrap : losing hit..." << std::endl;
    if (amount >= (unsigned int)hit)
      hit = 0;
    else
      hit = hit - amount;
  }
}

void ClapTrap::beRepaired(unsigned int amount){
	if (energy == 0 || hit == 0)
		std::cout << " 🤖 ClapTrap : no energy or hit points!" << std::endl;
	else
	{
		std::cout<<" 🤖 ClapTrap : charge hit loading ..."<<std::endl;
		hit += amount;
		energy-=1;
	}
}

int ClapTrap::gethitPoints()
{
	return(hit);
}