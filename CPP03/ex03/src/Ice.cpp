/* --- Ice.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "Ice.h"
#include <iostream>

Ice::Ice() : AMateria("ice") { }
Ice::Ice(Ice const &other) : AMateria(other.type) { }

Ice::~Ice() {
    // Destructor
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
