#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(){
	for(int i = 0; i < 4; i++){
		tab[i] = 0;
}}

MateriaSource::MateriaSource(MateriaSource const &obj){
	*this = obj;
}

MateriaSource & MateriaSource::operator=(MateriaSource const &obj){
	for(int i = 0; i < 4; i++){
		if (tab[i])
			delete tab[i];
		if (obj.tab[i])
			tab[i] = (obj.tab[i])->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++){
		if (tab[i])
			delete tab[i];
	}
}

void MateriaSource::learnMateria(AMateria *m){
	int i = 0;

	while (tab[i] != 0 && i < 4)
		i++;
	if (i >= 4)
		return ;
	tab[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const &type){
	int i = 0;

	while (tab[i] && (tab[i])->getType() != type && i < 4)
		i++;
	if (i >= 4 || !tab[i]){
		return (NULL);
	}
	return ((tab[i])->clone());
}