#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called"<<std::endl;
    value = 0;
}

Fixed::~Fixed(){
    std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const int intVal){
    std::cout << "Int constructor called"<<std::endl;
    value = intVal << fractionalbits;
}

Fixed::Fixed(const float floatVal){
    std::cout<<"Float constructor called"<<std::endl;
    value = (int)round(floatVal *(float)(1 << fractionalbits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout<<"Copy constructor called"<<std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        value = other.value;
    }
    return *this;
}

float Fixed::toFloat() const {
    return static_cast<float>(value / static_cast<float>(1 << fractionalbits));
}

int Fixed::toInt() const {
    return value >> fractionalbits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}
