/* --- HumanA.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/24/2025
------------------------------------------ */

#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon &weapon)
    : weapon(weapon), name(name) { }

void HumanA::attack() const
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
