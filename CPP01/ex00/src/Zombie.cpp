/* --- Zombie.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/23/2025
------------------------------------------ */

#include "Zombie.h"
#include <iostream>

Zombie::Zombie(std::string const& name) : name(name) {
    // Constructor
}

Zombie::~Zombie() {
    std::cout << this->name << " died\n";
}

void Zombie::announce(void) const {
    std::cout << this -> name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
