#include "wronganimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "wrong anuimal : default constructor called" << std::endl;
    type = "Wrong Animal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj){
    std::cout << "wrong animal : copy constructor called" << std::endl;
    *this = obj;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj){
    std::cout << "wrong anuimal : assignement constructor called" << std::endl;
    if (this != &obj){
        this->type = obj.type;
    }
    return(*this);
}

WrongAnimal::~WrongAnimal(){
    std::cout << "wrong anuimal : destructor called" << std::endl;
}

std::string WrongAnimal::getType() const{
    return(type);
}

void WrongAnimal::WrongAnimal::makeSound() const{
    std::cout << "wrong animal : cats don’t bark" << std::endl; 
}
