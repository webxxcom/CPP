/* --- Point.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "Point.h"

Point::Point() {
    // Constructor
}

Point::Point(Point const &other)
        : x(other.x), y(other.y) { }

Point::Point(Fixed const x, Fixed const y)
        : x(x), y(y) { }

Point::~Point()
{
    // Destructor
}

Fixed const &Point::getY() const { return y; }
Fixed const &Point::getX() const { return x; }

Point &Point::operator=(Point const &other)
{
    (void)other;
    return (*this);
}