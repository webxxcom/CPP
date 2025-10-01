/* --- Zombie.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/23/2025
------------------------------------------ */

#pragma once

#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string const& name);

    ~Zombie();
    
    void announce(void) const;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);
