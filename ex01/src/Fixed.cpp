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

std::ostream &operator<<(std::ostream &output, const Fixed &value){
    output << value.toFloat();
    return (output);
}

float Fixed::toFloat( void ) const{
    return ((float)this->value / (float)(1 << Fixed::bits));
}

int Fixed::toInt( void ) const{
    return (this->value >> Fixed::bits);
    
}

Fixed::Fixed(int const value){
    this->value = value << Fixed::bits;
}

Fixed::Fixed(float const value){
    this->value = roundf(value * (1 << Fixed::bits));
}