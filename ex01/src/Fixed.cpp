#include "../include/Fixed.hpp"

Fixed::Fixed(void) {
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = fixed.getRawBits();
}

Fixed::Fixed(const int val)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = val << this->bits;
}

Fixed::Fixed(const float val)
{
    std::cout << "Float  constructor called" << std::endl;
    this->value = roundf(val * (1 << this->bits));
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Assignation operator called" << std::endl;
   this->value = other.getRawBits();
   return(*this);
}

int Fixed::getRawBits( void ) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits ( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float Fixed::toFloat( void ) const {
    return ((float)this->value / (float)(1 << Fixed::bits));
}

int Fixed::toInt( void ) const {
    return (this->value >> Fixed::bits);
}

std::ostream &operator<<(std::ostream &output, const Fixed &value){
    output << value.toFloat();
    return (output);
}