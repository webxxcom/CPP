/* --- AMateria.h --- */
#include <string>

/* ------------------------------------------
Author: Webxxcom
Date: 9/30/2025
------------------------------------------ */

#pragma once

#include "ICharacter.h"

class AMateria
{
protected:
    std::string type;

public:
    AMateria(std::string const& type);
    virtual ~AMateria() {};

    std::string const& getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};
