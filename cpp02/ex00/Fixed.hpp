#pragma once

#include <iostream>


class Fixed{
    private:
        int store;
        static const int number; 

    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits() const;  
        void setRawBits(int const raw) ;
};
