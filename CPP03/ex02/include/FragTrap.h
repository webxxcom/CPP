/* --- FragTrap.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 10/29/2025
------------------------------------------ */

#pragma once

#include "ClapTrap.h"

class FragTrap : public ClapTrap{
private:
public:
    FragTrap(std::string const& name);
    virtual ~FragTrap();
    FragTrap(FragTrap const& other);
    FragTrap& operator=(FragTrap const& other);

    virtual void attack(std::string const& name);
    void highFivesGuys(void);
};
