/* --- Cat.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/30/2025
------------------------------------------ */

#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
private:

public:
    Cat();
    ~Cat();

    void makeSound() const;
};

#endif // CAT_H
