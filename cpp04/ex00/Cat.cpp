#include "Cat.hpp"

Cat::Cat() : Animal(){
    std::cout << "cat : default constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &obj) : Animal(obj){
    std::cout << "Cat : copy constructor called" << std::endl;
    *this = obj;
}

Cat &Cat::operator=(const Cat &obj){
    std::cout << "Cat : assignement constructor called" << std::endl;
    if (this != &obj){
        this->type = obj.type;
    }
    return(*this);}

Cat::~Cat(){
    std::cout << "Cat : destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "cat : make sound" << std::endl;
}

std::string Cat::getType() const{
    return (this->type);
}