/* --- Cat.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "Cat.h"

Cat::Cat() : Animal("Cat")
{
}

Cat::~Cat() {
}

void Cat::makeSound() const
{
    std::cout << "Meoooooowwww" << std::endl;
}
