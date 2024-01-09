#pragma once

#include <iostream>

class Fixed{
    private:
        int value;
        static const int fractionalbits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed(const int intval);
        Fixed(const float floatval);
        float   toFloat(void) const;
        int toInt(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        Fixed   &operator=(const Fixed &a);
        bool    operator>(const Fixed &a);
        bool    operator<(const Fixed &a);
        bool    operator>=(const Fixed &a);
        bool    operator<=(const Fixed &a);
        bool    operator==(const Fixed &a);
        bool    operator!=(const Fixed &a);
        Fixed   operator+(const Fixed &a);
        Fixed   operator-(const Fixed &a);
        Fixed   operator*(const Fixed &a);
        Fixed   operator/(const Fixed &a);
        Fixed   &operator++(void);
        Fixed   operator++(int);
        Fixed   &operator--(void);
        Fixed   operator--(int);
        static  Fixed &min(Fixed &a, Fixed &b);
        static  const Fixed &min(const Fixed &a, const Fixed &b);
        static  Fixed &max(Fixed &a, Fixed &b);
        static  const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

