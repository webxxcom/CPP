/* --- HumanB.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/24/2025
------------------------------------------ */

#pragma once

#include "Weapon.h"

class HumanB
{
private:
    std::string name;
    Weapon *weapon;

public:
    HumanB();
    HumanB(std::string name);

    void attack() const;
    const Weapon *getWeapon() const;
    void setWeapon(Weapon &weapon);
};
