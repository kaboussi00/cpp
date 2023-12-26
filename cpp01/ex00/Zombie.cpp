#include "Zombie.hpp"

Zombie::Zombie(){
        this->name = "";
};

Zombie::Zombie(std::string zombieName) {
        this->name = zombieName;
}

Zombie::~Zombie(){
        std::cout<<"bye zombie !!"<<std::endl;
}

void Zombie::announce() {
        std::cout <<name<< ": BraiiiiiiinnnzzzZ..." << std::endl;
};
