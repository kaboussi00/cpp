#include <iostream>

#include <iostream>
#include <string>

class ClapTrap{
		protected:
			std::string name;
			unsigned int hit;
			unsigned int energy;
			unsigned int attackDamage;
		public:
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap &obj);
			ClapTrap &operator=(const ClapTrap &obj);
			~ClapTrap();
			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
			int gethitPoints();
};