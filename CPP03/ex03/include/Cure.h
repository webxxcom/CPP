/* --- Cure.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/30/2025
------------------------------------------ */

#pragma once

#include "AMateria.h"

class Cure : public AMateria
{
private:

public:
    Cure();
    Cure(Cure const& other);
    ~Cure();

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};
