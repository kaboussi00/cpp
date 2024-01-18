#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Aanimal(){
    std::cout << "cat : default constructor called" << std::endl;
    bcat = new Brain;
}

Cat::Cat(const Cat &obj) : Aanimal(obj){
    std::cout << "Cat : copy constructor called" << std::endl;
    bcat = new Brain(*obj.bcat);
}

Cat &Cat::operator=(const Cat &obj){
    std::cout << "Cat : assignement constructor called" << std::endl;
    if (this != &obj){
        this->~Cat();
        Aanimal::operator=(obj);   
        bcat = new Brain(*obj.bcat);
    }
    return(*this);
}

Brain   const Cat::getBrain() const{
    return(*bcat);
}

Cat::~Cat(){
    std::cout << "Cat : destructor called" << std::endl;
    delete bcat;
}

void Cat::makeSound() const{
    std::cout << "cat : make sound" << std::endl;
} 