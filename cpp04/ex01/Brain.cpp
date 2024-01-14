#include "Brain.hpp"

Brain::Brain(){
    std::cout<< "brain : default constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
            ideas[i] = "";}
}

Brain::Brain(const Brain &obj) {
    std::cout<< "brain : copy constructor called" << std::endl;
    *this = obj;
}

Brain &Brain::operator=(const Brain &obj){
    std::cout << "brain : assignement operator called" << std::endl;
    if (this != &obj)
    {
        for (int i = 0; i++;){
            ideas[i] = obj.ideas[i];
        }
    }
    return(*this);
}

std::string Brain::getideas(int i){
    return(ideas[i]);
}

void Brain::setideas(int i, std::string idea){
    ideas[i] = idea;
}

Brain::~Brain(){
    std::cout << "brain : destructor called" << std::endl;
}
