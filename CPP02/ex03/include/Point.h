/* --- Point.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/30/2025
------------------------------------------ */

#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point {
private:
    Fixed const x;
    Fixed const y;

public:
    Point();
    Point(Point const& other);
    Point(Fixed const x, Fixed const y);
    ~Point();

    Fixed const& getY() const;
    Fixed const& getX() const;
    
    Point &operator=(Point const& other);
};

#endif // POINT_H
