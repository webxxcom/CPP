/* --- Fixed.cpp --- */

/* ------------------------------------------
author: undefined
date: 9/27/2025
------------------------------------------ */

#include "Fixed.h"
#include <cmath>

Fixed::Fixed(int const raw_bits, bool) : raw(raw_bits) { }
Fixed::Fixed() : raw(0) { }
Fixed::Fixed(Fixed const &other) { *this = other; }
Fixed::Fixed(int const num) { raw = num << bits; }
Fixed::Fixed(float const num) { raw = roundf(num * (1 << bits)); }
Fixed::~Fixed() { }

int Fixed::getRawBits(void) const
{
	return (this->raw);
}

void Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}

int Fixed::toInt(void) const
{
	return this->raw >> this->bits;
}

float Fixed::toFloat(void) const
{
	return ((float)raw / (1 << bits));
}

Fixed &Fixed::min(Fixed &left, Fixed &right)
{
    return left.raw <= right.raw ? left : right;
}

Fixed const& Fixed::min(Fixed const &left, Fixed const &right)
{
	return left.raw <= right.raw ? left : right;
}

Fixed &Fixed::max(Fixed &left, Fixed &right)
{
	return left.raw > right.raw ? left : right;
}

Fixed const& Fixed::max(Fixed const &left, Fixed const &right)
{
	return left.raw > right.raw ? left : right;
}

Fixed &Fixed::operator=(Fixed const &other)
{
	this->setRawBits(other.getRawBits());
	return (*this);
}

bool Fixed::operator>(Fixed const &other) { return this->raw > other.raw; }
bool Fixed::operator>=(Fixed const &other) { return this->raw >= other.raw; }
bool Fixed::operator<(Fixed const &other) { return this->raw < other.raw; }
bool Fixed::operator<=(Fixed const &other) { return this->raw <= other.raw; }
bool Fixed::operator==(Fixed const &other) { return (this->raw == other.raw); }
bool Fixed::operator!=(Fixed const &other) { return this->raw != other.raw; }

Fixed Fixed::operator+(Fixed const &other) { return Fixed(this->raw + other.raw, 1); }
Fixed Fixed::operator-(Fixed const &other) {return Fixed(this->raw - other.raw, 1); }

Fixed Fixed::operator*(Fixed const &other)
{
	int64_t raw_scaled_res = (int64_t)this->raw * (int64_t)other.raw;
	return Fixed(raw_scaled_res >> bits, 1);
}

Fixed Fixed::operator/(Fixed const &other)
{
	int raw_res = ((int64_t)this->raw << bits) / other.raw;
	return Fixed(raw_res, 1);
}

Fixed Fixed::operator++(int)
{
	Fixed cpy = *this;
	++this->raw;
    return cpy;
}

Fixed &Fixed::operator++()
{
    ++this->raw;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed cpy = *this;
	--this->raw;
	return cpy;
}

Fixed &Fixed::operator--()
{
	--this->raw;
	return (*this);
}

std::ostream &operator<<(std::ostream &ios, Fixed const &other)
{
	ios << other.toFloat();
	return (ios);
}
