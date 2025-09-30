/* --- AMateria.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "AMateria.h"


AMateria::AMateria(std::string const &type) :type(type) { }

std::string const &AMateria::getType() const { return this->type; }

void AMateria::use(ICharacter &target)
{
    (void)target;
}
