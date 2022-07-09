#include "../include/Fixed.hpp"

Fixed::Fixed(void){
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &another){
    std::cout << "Copy constructor called" << std::endl;
    *this = another;
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits ( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

Fixed &Fixed::operator=(const Fixed &other){
    std::cout << "Assignation operator called" << std::endl;
   this->value = other.getRawBits();
   return(*this);
}