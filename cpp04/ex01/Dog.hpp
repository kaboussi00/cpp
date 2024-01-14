#pragma once

#include "Animal.hpp"

class Dog : public Animal{
    private :
        Brain *bdog;
    public :
        Dog();
        Dog(const Dog &obj);
        Dog &operator=(const Dog &obj);
        ~Dog();
        Brain const getBrain();
        void makeSound() const;
};