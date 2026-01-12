/* --- Fixed.h --- */

/* ------------------------------------------
Author: undefined
Date: 9/27/2025
------------------------------------------ */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <ostream>
#include <ios>

class Fixed {
private:
    static const int bits = 8;
    int raw;

    Fixed(int const raw_bits, bool);
public:
    Fixed();
    Fixed(Fixed const &other);
    explicit Fixed(int const num);
    explicit Fixed(float const num);
    ~Fixed();
    
    int getRawBits(void) const;
    void setRawBits(int const raw);

    int toInt(void) const;
    float toFloat(void) const;

    static Fixed &min(Fixed &left, Fixed &right);
    static Fixed const& min(Fixed const &left, Fixed const &right);

    static Fixed &max(Fixed &left, Fixed &right);
    static Fixed const& max(Fixed const &left, Fixed const &right);

    Fixed &operator=(Fixed const& other);
    friend std::ostream &operator<<(std::ostream &ios, Fixed const& other);

    // Comparison operators
    bool operator>(Fixed const &other);
    bool operator>=(Fixed const &other);
    bool operator<(Fixed const &other);
    bool operator<=(Fixed const &other);
    bool operator==(Fixed const &other);
    bool operator!=(Fixed const &other);

    // Arithmetic operators
    Fixed operator+(Fixed const &other) const;
    Fixed operator-(Fixed const &other) const;
    Fixed operator*(Fixed const &other) const;
    Fixed operator/(Fixed const &other) const;

    // Increment/decrement operators
    Fixed operator++(int);
    Fixed &operator++();
    Fixed operator--(int);
    Fixed &operator--();
};

#endif // FIXED_H
