/* --- Fixed.cpp --- */

/* ------------------------------------------
author: undefined
date: 9/27/2025
------------------------------------------ */

#include "Fixed.h"
#include <iostream>

Fixed::Fixed() : num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (num);
}

void Fixed::setRawBits(int const raw)
{
    num = raw;
}

Fixed &Fixed::operator=(Fixed const& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
    return (*this);
}
