
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    public:
        Fixed();
        ~Fixed();
        Fixed (const Fixed &fixed);
        Fixed (const int val);
        Fixed (const float val);
        Fixed & operator =(const Fixed &fixed);
        int getRawBits( void ) const;
        void setRawBits (int const raw );
        int toInt() const;
        float toFloat() const;

    private:
        int     value;
        static const int bits = 8; 
};

std::ostream& operator<<(std::ostream& out, const Fixed& origin);

#endif