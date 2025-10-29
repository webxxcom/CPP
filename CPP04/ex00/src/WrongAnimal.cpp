/* --- WrongAnimal.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal(std::string const& type)
        :type(type) { }

WrongAnimal::~WrongAnimal()
{
    std::cout << "Wrong animal destructor is called\n";
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong animal does not have any sound\n";
}
