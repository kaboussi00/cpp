#pragma once

#include "Brain.hpp"

class Brain;

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string name);
        Animal(const Animal &obj);
        Animal &operator=(const Animal &obj);
        std::string getType() const;
        virtual ~Animal();
        virtual void makeSound() const;
};