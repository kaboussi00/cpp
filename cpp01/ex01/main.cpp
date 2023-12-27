#include "Zombie.hpp"

int main() {
    int numberZombies = 5;
    std::string Name = "Braaainnss";

    Zombie* horde = zombieHorde(numberZombies, Name);

    for (int i = 0; i < numberZombies; ++i) {
        horde[i].announce();
    }

    delete[] horde;

    return 0;
}