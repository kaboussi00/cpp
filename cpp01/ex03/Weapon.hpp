#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Weapon{
private:
    std::string type;

public:
    Weapon(std::string weapontype);

    const std::string &getType();

    void setType(std::string newtype);
};