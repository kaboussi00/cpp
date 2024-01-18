#pragma once

#include "Aanimal.hpp"
#include "Brain.hpp"

class Cat : public Aanimal{
    private :
        Brain *bcat;
    public :
        Cat();
        Cat(const Cat &obj);
        Cat &operator=(const Cat &obj);
        ~Cat();
        Brain   const getBrain() const;
        void makeSound() const;
};