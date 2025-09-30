/* --- HumanB.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/24/2025
------------------------------------------ */

#include "HumanB.h"

HumanB::HumanB() : name(), weapon()
{
}

HumanB::HumanB(std::string name) : name(name), weapon()
{
}

HumanB::~HumanB()
{
    // Destructor
}

const Weapon *HumanB::getWeapon() const { return weapon; }

void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }

void HumanB::attack() const
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
