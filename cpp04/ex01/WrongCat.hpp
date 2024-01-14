#pragma once

#include "wronganimal.hpp"

class WrongCat : public WrongAnimal{
    public : 
        WrongCat();
        WrongCat(const WrongCat &obj);
        WrongCat &operator=(const WrongCat &obj);
        ~WrongCat();
        std::string getType() const;
        void makeSound() const;
};
