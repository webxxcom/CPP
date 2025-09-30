/* --- WrongCat.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/30/2025
------------------------------------------ */

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
private:

public:
    WrongCat();
    ~WrongCat();

    void makeSound() const;
};

#endif // WRONGCAT_H
