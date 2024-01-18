#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
    std::cout << "Wrong cat : default constructor called" << std::endl;
    type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj){
    std::cout << "Wrong Cat : copy constructor called" << std::endl;
    *this = obj;
}

WrongCat &WrongCat::operator=(const WrongCat &obj){
    std::cout << "Wrong Cat : assignement constructor called" << std::endl;
    if (this != &obj){
        this->type = obj.type;
    }
    return(*this);
}

WrongCat::~WrongCat(){
    std::cout << "Wrong Cat : destructor called" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "Wrong cat : make sound" << std::endl;
}

std::string WrongCat::getType() const{
    return (type);
}