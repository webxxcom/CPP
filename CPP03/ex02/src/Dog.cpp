/* --- Dog.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "Dog.h"

Dog::Dog() : Animal("Dog")
{
}

Dog::~Dog() {
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}
