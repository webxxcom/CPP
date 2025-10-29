/* --- Animal.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "Animal.h"

Animal::Animal()
        : type(""), brain(NULL)
{
}

Animal::Animal(std::string const &type)
        : type(type), brain(new Brain())
{
}

Animal::Animal(Animal const &other)
        : type(other.type), brain(new Brain(*other.brain))
{
}

Animal &Animal::operator=(Animal const &other)
{
    if (this != &other)
    {
        this->type = other.type;
        if (this->brain)
            delete brain;
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

Animal::~Animal() {
    delete brain;
}

std::string const& Animal::getType() const
{
    return this->type;
}

Brain *const &Animal::getBrain() const
{
    return this->brain;
}

void Animal::setType(std::string const &type)
{
    this->type = type;
}

void Animal::makeSound() const
{
    std::cout << "Simple animal does not have any sound" << std::endl;
}
