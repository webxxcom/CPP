/* --- DiamondTrap.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 10/29/2025
------------------------------------------ */

#pragma once

#include "ScavTrap.h"
#include "FragTrap.h"

class DiamondTrap : public FragTrap, public ScavTrap{
private:
    std::string name;
public:
    DiamondTrap(std::string const& name);
    ~DiamondTrap();
    DiamondTrap(DiamondTrap const& other);
    DiamondTrap& operator=(DiamondTrap const& other);

    void attack(std::string const& target);
    void whoAmI(void);
};
