/* --- HumanA.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/24/2025
------------------------------------------ */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

class HumanA {
private:
    Weapon &weapon;
    std::string name;

public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();

    void attack() const;
};

#endif // HUMANA_H
