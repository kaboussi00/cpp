#pragma once

#include "Aanimal.hpp"
#include "Brain.hpp"

class Dog : public Aanimal{
    private :
        Brain *bdog;
    public :
        Dog();
        Dog(const Dog &obj);
        Dog &operator=(const Dog &obj);
        ~Dog();
        void makeSound() const;
        Brain   const getBrain() const;
};