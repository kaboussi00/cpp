#include "Dog.hpp"

Dog::Dog() : Animal(){
    std::cout << "Dog : default constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &obj) : Animal(obj){
    std::cout << "Dog : copy constructor called" << std::endl;
    *this = obj;
}

Dog &Dog::operator=(const Dog &obj){
    std::cout << "Dog : assignement constructor called" << std::endl;
    if (this != &obj){
        this->type = obj.type;
    }
    return(*this);
}

Dog::~Dog(){
    std::cout << "Dog : destructor called" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Dog : makeSound" << std::endl;
}

std::string Dog::getType() const{
    return (this->type);
}
