#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		std::string type;
	public:
		Cure();
		Cure(Cure const &obj);
		Cure &operator=(Cure const &obj);
		~Cure();
		std::string const &getType() const;
		Cure *clone() const;
		void use(ICharacter &target);
};