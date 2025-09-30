/* --- Cure.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "Cure.h"
#include <iostream>

Cure::Cure() : AMateria("cure") { }
Cure::Cure(Cure const &other) : AMateria(other.type) { }

Cure::~Cure() {
    // Destructor
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
