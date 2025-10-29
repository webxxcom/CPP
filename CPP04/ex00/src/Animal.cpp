/* --- Animal.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "Animal.h"

Animal::Animal() : type("") { }
Animal::Animal(std::string const &type) : type(type) { }
Animal::Animal(Animal const &other) : type(other.type) { }
Animal &Animal::operator=(Animal const &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

std::string const& Animal::getType() const { return this->type; }
void Animal::setType(std::string const &type) { this->type = type; }

void Animal::makeSound() const
{
    std::cout << "Simple animal does not have any sound" << std::endl;
}
