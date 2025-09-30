/* --- Zombie.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/23/2025
------------------------------------------ */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie();
    Zombie(std::string const& name);

    ~Zombie();
    
    void announce(void) const;
};

Zombie *zombieHorde(int N, std::string name);

#endif // ZOMBIE_H
