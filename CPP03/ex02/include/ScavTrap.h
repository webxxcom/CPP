/* --- ScavTrap.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 10/29/2025
------------------------------------------ */

#pragma once

#include "ClapTrap.h"

class ScavTrap : public ClapTrap{
private:

public:
    ScavTrap(std::string const& name);
    virtual ~ScavTrap();
    ScavTrap(ScavTrap const& other);
    ScavTrap& operator=(ScavTrap const& other);

    virtual void attack(const std::string& target);
    void guardGate();
};
