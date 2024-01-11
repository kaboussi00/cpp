#pragma once

#include <iostream>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &obj);
        Animal &operator=(const Animal &obj);
        std::string getType() const;
        virtual ~Animal();
        virtual void makeSound() const;
};
