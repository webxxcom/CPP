/* --- Ice.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/30/2025
------------------------------------------ */

#pragma once

#include "AMateria.h"

class Ice : public AMateria
{
private:

public:
    Ice();
    Ice(Ice const &other);
    ~Ice();

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};
