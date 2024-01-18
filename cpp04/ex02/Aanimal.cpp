#include "Aanimal.hpp"

Aanimal::Aanimal(){
    std::cout << "Aanimal : default constructor called" << std::endl;
    type = "Aanimal";
}

Aanimal::Aanimal(const Aanimal &obj){
    std::cout << "Aanimal : copy constructor called" << std::endl;
    *this = obj;
}

Aanimal &Aanimal::operator=(const Aanimal &obj){
    std::cout << "Aanimal : assignement constructor called" << std::endl;
    if (this != &obj){
        this->type = obj.type;
    }
    return(*this);
}

Aanimal::~Aanimal(){
    std::cout << "Aanimal : destructor called" << std::endl;
}

std::string Aanimal::getType() const{
    return(type);
}