/* --- Fixed.h --- */

/* ------------------------------------------
Author: undefined
Date: 9/27/2025
------------------------------------------ */

#ifndef FIXED_H
#define FIXED_H

class Fixed {
private:
    static const int bits = 8;
    int num;
public:
    Fixed();
    Fixed(Fixed const& other);
    ~Fixed();
    
    int getRawBits(void) const;
    void setRawBits(int const raw);

    Fixed &operator=(Fixed const& other);
};

#endif // FIXED_H
