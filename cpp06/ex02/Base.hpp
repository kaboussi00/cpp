#pragma once

#include <iostream>
#include <cstdint>
#include <cstdlib>

class Base{
    public :
        Base();
        virtual ~Base();
};

void identify(Base* p);

Base * generate(void);

void identify(Base& p);