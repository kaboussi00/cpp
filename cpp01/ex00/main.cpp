#include "Zombie.hpp"

int main() {
    Zombie* z = newZombie("kawtar");
    z->announce();

    randomChump("kawtaraboussi");

    delete (z);

    return 0;
}