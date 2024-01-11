#include "Animal.hpp"

Animal::Animal(){
    std::cout << "default constructor called" << std::endl;
    type = "Animal";
}

Animal::Animal(std::string name){
    std::cout << "param constructor called" << std::endl;
    type = name;
}

Animal::Animal(const Animal &obj){
    std::cout << "copy constructor called" << std::endl;
    *this = obj;
}

Animal &Animal::operator=(const Animal &obj){
    std::cout << "assignement constructor called" << std::endl;
    if (this != &obj){
        this->type = obj.type;
    }
    return(*this);
}

Animal::~Animal(){
    std::cout << "destructor called" << std::endl;
}

std::string Animal::getType() const{
    return(type);
}

void Animal::Animal::makeSound() const{
    std::cout << "cats don’t bark" << std::endl; 
}
