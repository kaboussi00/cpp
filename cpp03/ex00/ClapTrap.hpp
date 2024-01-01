#include <iostream>

#include <iostream>
#include <string>

class ClapTrap{
		private:
			std::string name;
			int hit;
			int energy;
			int attackDamage;
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
