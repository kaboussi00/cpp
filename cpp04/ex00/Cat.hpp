#pragma once

#include "Animal.hpp"

class Cat : public Animal{
    public :
        Cat();
        Cat(const Cat &obj);
        Cat &operator=(const Cat &obj);
        ~Cat();
        std::string getType() const;
        void makeSound() const;
}; 