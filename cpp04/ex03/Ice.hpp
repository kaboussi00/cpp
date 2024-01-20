#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		std::string type;
	public:
		Ice();
		~Ice();
		Ice(Ice const &obj);
		Ice & operator=(Ice const &obj);
		std::string const &getType() const;
		Ice *clone() const;
		void use(ICharacter& target);
};