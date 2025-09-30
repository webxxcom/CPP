/* --- Weapon.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/24/2025
------------------------------------------ */

#include "Weapon.h"

Weapon::Weapon() : type()
{
}

Weapon::Weapon(std::string type) : type(type)
{
}

Weapon::~Weapon()
{
    // Destructor
}

const std::string &Weapon::getType() const { return type; }

void Weapon::setType(std::string type) { this->type = type; }