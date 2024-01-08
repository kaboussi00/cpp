#pragma once

#include <iostream>

class Fixed{
    private:
        int value;
        static const int fractionalbits = 8; 
    public:
        Fixed();
        Fixed(const int intVal);
        Fixed(const float floatVal);
        Fixed(const Fixed& other);
        int toInt() const;
        float toFloat() const;
        Fixed& operator=(const Fixed& other);
        ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);