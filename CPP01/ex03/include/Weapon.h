/* --- Weapon.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/24/2025
------------------------------------------ */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon {
private:
    std::string type;

public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();


    const std::string& getType() const ;
    void setType(std::string type);

};

#endif // WEAPON_H
