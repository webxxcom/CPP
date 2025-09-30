/* --- Dog.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/30/2025
------------------------------------------ */

#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal
{
private:

public:
    Dog();
    ~Dog();

    void makeSound() const;
};

#endif // DOG_H
