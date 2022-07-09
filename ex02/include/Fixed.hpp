
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    public:
        Fixed(void);
        Fixed(int const value);
        Fixed(float const value);
        ~Fixed(void);
        Fixed(Fixed const &another);
        Fixed &operator=(const Fixed &other);


        int getRawBits( void ) const;
        void setRawBits ( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const; 

        //Ex02
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
        Fixed operator+(const Fixed &other);
        Fixed operator-(const Fixed &other);
        Fixed operator*(const Fixed &other);
        Fixed operator/(const Fixed &other);
        Fixed& operator--();
		Fixed operator--(int);
		Fixed& operator++();
		Fixed operator++(int);

    private:
        int     value;
        static const int bits = 8; 
};

std::ostream& operator<<(std::ostream& out, const Fixed& origin);

#endif