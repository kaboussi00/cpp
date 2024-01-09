#include "Fixed.hpp"

Fixed::Fixed(){
    value = 0;
}

Fixed::~Fixed(){}

Fixed::Fixed(const Fixed& other){
    *this = other; 
}

Fixed::Fixed(const int intval){
    value = intval << fractionalbits;
}

Fixed::Fixed(const float floatval){
    value = (int)round(floatval *(float)(1 << fractionalbits));
}

int Fixed::getRawBits(void) const
{
    return (value);
}

void Fixed::setRawBits(int const raw) {
    value = raw;
}

int     Fixed::toInt(void) const
{
    return ((int)(value >> fractionalbits));
}

float     Fixed::toFloat(void) const
{
    return ((float)(value / (float)(1 << fractionalbits)));
}

Fixed &Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed a(*this);
    this->value+= 1;
    return a;
}

Fixed &Fixed::operator++() {
    this->value += 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed a(*this);
    this->value-= 1;
    return a;
}

Fixed &Fixed::operator--() {
    this->value -= 1;
    return *this;
}


bool    Fixed::operator>=(const Fixed &a)
{
    return (this->value >= a.value);
}

bool    Fixed::operator<=(const Fixed &a)
{
    return (this->value <= a.value);
}

bool    Fixed::operator==(const Fixed &a)
{
    return (this->value == a.value);
}

bool    Fixed::operator!=(const Fixed &a)
{
    return (this->value!= a.value);
}

Fixed   Fixed::operator+(const Fixed &a)
{
    Fixed   res;

    res.setRawBits(this->value+ a.value);
    return (res);
}

Fixed   Fixed::operator-(const Fixed &a)
{
    Fixed   res;

    res.setRawBits(this->value- a.value);
    return (res);
}

Fixed   Fixed::operator*(const Fixed &a)
{
    Fixed   tmp;

    tmp.value= (this->value* a.value) >> fractionalbits;
    return (tmp);
}

Fixed   Fixed::operator/(const Fixed &a)
{
    Fixed   tmp;

    if (a.getRawBits() == 0)
        return (-1);
    tmp.setRawBits(this->value / a.value);
    return (tmp);
}

bool    Fixed::operator>(const Fixed &a)
{
    return (this->value > a.value);
}

bool    Fixed::operator<(const Fixed &a)
{
    return (this->value < a.value);
}

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
    if (x < y)
        return (x);
    return (y);
}

const Fixed &Fixed::min(const Fixed &x, const Fixed &y)
{
    if ((Fixed)x < y)
        return (x);
    return (y);
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
    if (x > y)
        return (x);
    return (y);
}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y)
{
    if ((Fixed)x > y)
        return (x);
    return (y);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}