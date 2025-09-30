/* --- HumanB.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/24/2025
------------------------------------------ */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"

class HumanB
{
private:
    std::string name;
    Weapon *weapon;

public:
    HumanB();
    HumanB(std::string name);
    ~HumanB();

    void attack() const;
    const Weapon *getWeapon() const;
    void setWeapon(Weapon &weapon);
};

#endif // HUMANB_H
