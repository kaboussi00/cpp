#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called"<<std::endl;
    store = 0;
}

Fixed::~Fixed(){
    std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout<<"Copy constructor called"<<std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout<< "Copy assignment operator called" <<std::endl;
    if (this != &other) {
        getRawBits();
        store = other.store;
    }
    return *this;
}

int Fixed::getRawBits() const {
    std::cout<< "getRawBits member function called" <<std::endl;
    return store;
}

void Fixed::setRawBits(int const raw) {
    store = raw;
}
