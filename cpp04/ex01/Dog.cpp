#include "Dog.hpp"

Dog::Dog() : Animal(){
    std::cout << "Dog : default constructor called" << std::endl;
    bdog = new Brain; 
}

Dog::Dog(const Dog &obj) : Animal(obj){
    std::cout << "Dog : copy constructor called" << std::endl;
    bdog = new Brain(*obj.bdog);
}

Dog &Dog::operator=(const Dog &obj){
    std::cout << "Dog : assignement constructor called" << std::endl;
    if (this != &obj){
        this->~Dog();
        Animal::operator=(obj);
        bdog = new Brain(*obj.bdog);
    }
    return(*this);
}

Dog::~Dog(){
    std::cout << "Dog : destructor called" << std::endl;
    delete bdog;
}

void Dog::makeSound() const{
    std::cout << "Dog : makeSound" << std::endl;
}

Brain   const Dog::getBrain(){
    return (*bdog);
}