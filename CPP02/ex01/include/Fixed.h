/* --- Fixed.h --- */

/* ------------------------------------------
Author: undefined
Date: 9/27/2025
------------------------------------------ */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
private:
    static const int bits = 8;
    int raw;

    int getDecimalPart(void) const;
    double getFractionalPart(void) const;
public:
    Fixed();
    Fixed(Fixed const& other);
    Fixed(int const num);
    Fixed(float const num);
    ~Fixed();
    
    int getRawBits(void) const;
    void setRawBits(int const raw);

    int toInt(void) const;
    float toFloat(void) const;

    Fixed &operator=(Fixed const& other);
    friend std::ostream &operator<<(std::ostream &ios, Fixed const& other);
};

#endif // FIXED_H
