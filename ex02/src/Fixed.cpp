#include <iostream>
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
    std::cout << "getRawBits member function called" << std::endl;
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

Fixed Fixed::operator+(const Fixed &other)
{
    Fixed aux;
    aux.setRawBits(this->value + other.getRawBits());
    return (aux);
}

Fixed Fixed::operator-(const Fixed &other)
{
    Fixed aux;
    aux.setRawBits(this->value - other.getRawBits());
    return (aux);
}

Fixed Fixed::operator*(const Fixed &other)
{
    Fixed aux;
    float num;
    num = this->toFloat() *  other.toFloat();
    aux.setRawBits(roundf(num * (1 << this->bits)));
    return(aux);
}

Fixed Fixed::operator/(const Fixed &other)
{
    Fixed aux;
    float num;

    num = this->toFloat() / other.toFloat();
    aux.setRawBits(roundf(num * (1 << this->bits)));
    return(aux);
}

Fixed& Fixed::operator++()
{
    this->value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed aux;
    aux = *this;
    ++*this;
    return aux;
}

Fixed& Fixed::operator--()
{
    this->value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed aux;
    aux = *this;
    --*this;
    return aux;
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->value < other.getRawBits());
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->value > other.getRawBits());
}
bool Fixed::operator==(const Fixed &other) const
{
    return (this->value == other.getRawBits());
}
bool Fixed::operator!=(const Fixed &other) const
{
    return (this->value != other.getRawBits());
} 
bool Fixed::operator>=(const Fixed &other) const
{
    return (this->value >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed &other) const
{
    return (this->value <= other.getRawBits());
}

const Fixed &Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
    if (fix1 > fix2)
        return (fix1);
    return(fix2);
}
Fixed &Fixed::max(Fixed &fix1, Fixed &fix2)
{
    if (fix1 > fix2)
        return (fix1);
    return(fix2);
}

const Fixed &Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
    if (fix1 < fix2)
        return (fix1);
    return(fix2);
}

Fixed &Fixed::min(Fixed &fix1, Fixed &fix2)
{
    if(fix1 < fix2)
        return (fix1);
    return(fix2);
}

