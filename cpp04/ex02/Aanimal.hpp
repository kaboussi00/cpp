#pragma once

#include <iostream>

class Aanimal {
    protected:
        std::string type;
    public:
        Aanimal();
        Aanimal(const Aanimal &obj);
        Aanimal &operator=(const Aanimal &obj);
        virtual ~Aanimal();
        std::string getType() const;
        virtual void makeSound() const = 0;
};