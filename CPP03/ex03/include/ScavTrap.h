/* --- ScavTrap.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 10/29/2025
------------------------------------------ */

#pragma once

#include "ClapTrap.h"

class ScavTrap : virtual public ClapTrap{
public:
    ScavTrap(std::string const& name);
    virtual ~ScavTrap();
    ScavTrap(ScavTrap const& other);
    ScavTrap& operator=(ScavTrap const& other);

    void attack(std::string const& target);
    void guardGate(void);
};
