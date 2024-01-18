#include "Brain.hpp"

Brain::Brain(){
    std::cout<< "brain : default constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
            ideas[i] = "";}
}

Brain::Brain(std::string name){
    std::cout<< "brain : param constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
            ideas[i] = name;}
}

Brain::Brain(const Brain& obj) {
    std::cout<< "brain : copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
            ideas[i] = obj.ideas[i];}
}

Brain &Brain::operator=(const Brain &obj){
    std::cout << "brain : assignement operator called" << std::endl;
    if (this != &obj)
    {
        for (int i = 0; i<100; i++){
            ideas[i] = obj.ideas[i];
        }
    }
    return(*this);
}

std::string Brain::getideas(int i){
    return(ideas[i]);
}
void Brain::setideas(std::string idea, int i){
    ideas[i]=idea;
}

Brain::~Brain(){
    std::cout << "brain : estructor called" << std::endl;
}