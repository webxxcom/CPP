/* --- Fixed.cpp --- */

/* ------------------------------------------
author: undefined
date: 9/27/2025
------------------------------------------ */

#include "Fixed.h"
#include <cmath>

int Fixed::getDecimalPart(void) const
{
	return (this->raw >> this->bits);
}

double Fixed::getFractionalPart(void) const
{
	const int shift = sizeof(raw) * 8 - bits;
	return (this->raw << shift >> shift);
}

Fixed::Fixed() : raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(int const num)
{
	raw = num << bits;
}

Fixed::Fixed(float const num)
{
	raw = roundf(num * (1 << bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw);
}

void Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}

int Fixed::toInt(void) const
{
    return getDecimalPart();
}

float Fixed::toFloat(void) const
{
	return ((float)raw / (1 << bits));
}

Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream &ios, Fixed const &other)
{
	ios << other.toFloat();
	return (ios);
}
