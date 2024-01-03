#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("YYYY");
	ScavTrap b(a);
	ScavTrap c;
	ClapTrap d;

	c = a;
	d = a;

	std::cout<<a.gethitPoints()<<std::endl;
	std::cout<<b.gethitPoints()<<std::endl;
	std::cout<<c.gethitPoints()<<std::endl;
	a.attack("XXXX");
	std::cout<<a.gethitPoints()<<std::endl;
	a.beRepaired(10);
	std::cout<<a.gethitPoints()<<std::endl;
	a.takeDamage(10);
	std::cout<<a.gethitPoints()<<std::endl;
	a.takeDamage(10);
	std::cout<<a.gethitPoints()<<std::endl;
	a.takeDamage(10);
	std::cout<<a.gethitPoints()<<std::endl;
    a.guardGate();
	std::cout<<a.gethitPoints()<<std::endl;
}