#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include <cstdio>

class Zombie {
private:
    std::string name;

public:
    Zombie();

    Zombie(std::string zombieName);

    ~Zombie();

    void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);