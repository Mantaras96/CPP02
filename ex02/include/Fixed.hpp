#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{

    public:
        Fixed(void);
        ~Fixed(void);
        Fixed (const Fixed &other);
        Fixed (const int val);
        Fixed (const float val);
        Fixed & operator =(const Fixed &other);
        int getRawBits( void ) const;
        void setRawBits (int const raw );
        // Basics
        Fixed operator +(const Fixed &other);
        Fixed operator -(const Fixed &other);
        Fixed operator *(const Fixed &other);
        Fixed operator /(const Fixed &other);
        Fixed& operator ++();
        Fixed operator ++(int);
        Fixed& operator --();
        Fixed operator --(int);
        //Comparators
        bool operator <(const Fixed &other) const;
        bool operator >(const Fixed &other) const;
        bool operator <=(const Fixed &other) const;
        bool operator >=(const Fixed &other) const;
        bool operator ==(const Fixed &other) const;
        bool operator !=(const Fixed &other) const;
        // Comparators max and min 
        static const Fixed &min(const Fixed &fix1, const Fixed &fix2);
        static Fixed &min(Fixed &fix1, Fixed &fix2);
        static const Fixed &max(const Fixed &fix1, const Fixed &fix2);
        static Fixed &max(Fixed &fix1, Fixed &fix2);
        int toInt() const;
        float toFloat() const;

    private:
        int     value;
        static const int bits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed &origin);

#endif  