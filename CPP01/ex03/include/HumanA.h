/* --- HumanA.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/24/2025
------------------------------------------ */

#pragma once

#include "Weapon.h"

class HumanA {
private:
    Weapon &weapon;
    std::string name;

public:
    HumanA(std::string name, Weapon &weapon);

    void attack() const;
};
