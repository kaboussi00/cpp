#include "Cat.hpp"

Cat::Cat() : Animal(){
    std::cout << "cat : default constructor called" << std::endl;
    bcat = new Brain;
}

Cat::Cat(const Cat &obj) : Animal(obj){
    std::cout << "Cat : copy constructor called" << std::endl;
    bcat = new Brain(*obj.bcat);
}

Cat &Cat::operator=(const Cat &obj){
    std::cout << "Cat : assignement constructor called" << std::endl;
    if (this != &obj){
        this->~Cat();
        Animal::operator=(obj);
        bcat = new Brain(*obj.bcat);
    }
    return(*this);
}

Cat::~Cat(){
    std::cout << "Cat : destructor called" << std::endl;
    delete bcat;
}

void Cat::makeSound() const{
    std::cout << "cat make sound" << std::endl;
}

Brain   const Cat::getBrain(){
    return (*bcat);
}
