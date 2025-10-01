/* --- Weapon.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/24/2025
------------------------------------------ */

#pragma once

#include <iostream>

class Weapon {
private:
    std::string type;

public:
    Weapon();
    Weapon(std::string type);

    const std::string& getType() const ;
    void setType(std::string type);

};
