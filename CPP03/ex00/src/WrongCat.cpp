/* --- WrongCat.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "WrongCat.h"

#include <iostream>

WrongCat::WrongCat()
        : WrongAnimal("WrongCat") {
    // Constructor
}

WrongCat::~WrongCat() {
    std::cout << "Wrong cat destructor called\n";
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong tries to meow\n";
}
