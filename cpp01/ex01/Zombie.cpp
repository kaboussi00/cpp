#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::~Zombie()
{}

Zombie::Zombie(std::string name) {
    this->name = name;
};

void Zombie::announce(){
    std::cout << "I am a zombie named " << name << "!" << std::endl;
};
