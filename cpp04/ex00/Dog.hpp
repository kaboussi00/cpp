#pragma once

#include "Animal.hpp"

class Dog : public Animal{
    public :
        Dog();
        Dog(const Dog &obj);
        Dog &operator=(const Dog &obj);
        ~Dog();
        std::string getType() const;
        void makeSound() const;
};