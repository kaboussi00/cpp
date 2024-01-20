#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria *(tab[4]);
		AMateria *(fl[1024]);
		std::string const name;
		static int j;
	public:
		Character(std::string name);
		Character(Character const &obj);
		~Character();
		Character &operator=(Character const &obj);
		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int i);
		void use(int i, ICharacter& target);
};