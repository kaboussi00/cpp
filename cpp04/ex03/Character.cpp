#include "Character.hpp"

int Character::j = 0;

Character::Character(std::string name) : name(name){
	for(int i = 0; i < 4; i++){
		tab[i] = 0;
	}
}

Character::~Character(){
	for (int i = 0; i < 4; i++){
		if (tab[i])
			delete tab[i];
	}
	for (int i = 0; i < 1024; i++){
		if (fl[i])
			delete fl[i];
	}
}

std::string const &Character::getName() const{
	return (name);
}

Character::Character(Character const &obj){
	*this = obj;
}

Character & Character::operator=(Character const &obj){
	for(int i = 0; i < 4; i++)
	{
		if (tab[i])
			delete tab[i];
		if (obj.tab[i])
			tab[i] = (obj.tab[i])->clone();
	}
	return (*this);
}

void Character::equip(AMateria* m)
{
	int i = 0;

	if (!m)
		return ;
	while (tab[i] != 0 && i < 4)
		i++;
	if (i >= 4)
		return ;
	tab[i] = m;
}

void Character::unequip(int i)
{
	if (i < 0 || i >= 4 || (!tab[i]))
		return;
	else
	{
		fl[Character::j++] = tab[i];
		tab[i] = 0;
	}
}

void Character::use(int i, ICharacter &target)
{
	if (i < 0 || i >= 4 || (!tab[i])){
		return ;}
	(tab[i])->use(target);
}
