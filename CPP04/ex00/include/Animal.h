/* --- Animal.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/30/2025
------------------------------------------ */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    Animal();
    explicit Animal(std::string const &type);
    Animal(Animal const &other);
    virtual ~Animal();

    Animal &operator=(Animal const &other);

    std::string const &getType() const;

    void setType(std::string const &type);

    virtual void makeSound() const;
};

#endif // ANIMAL_H
