#include "ClapTrap.hpp"


int main()
{
	ClapTrap a("YYYY");
	ClapTrap b(a);
	ClapTrap c;

	c = a;

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
}