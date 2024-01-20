#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria &obj);
        AMateria &operator=(const AMateria &obj);
        virtual std::string const &getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        virtual ~AMateria();
};