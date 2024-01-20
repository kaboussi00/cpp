#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* (tab[4]);
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &obj);
		~MateriaSource();
		MateriaSource &operator=(MateriaSource const &obj);
		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const &type);
};