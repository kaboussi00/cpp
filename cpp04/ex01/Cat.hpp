#pragma once

#include "Animal.hpp"

class Cat : public Animal{
    private :
        Brain *bcat;
    public :
        Cat();
        Cat(const Cat &obj);
        Cat &operator=(const Cat &obj);
        ~Cat();
        Brain const getBrain();
        void makeSound() const;
};