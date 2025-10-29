/* --- ClapTrap.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 10/29/2025
------------------------------------------ */

#pragma once

#include <string>
#include <iostream>

class ClapTrap {
protected:
	std::string name;
	unsigned int hit_points;
	unsigned int energy_points;
	unsigned int attack_damage;

	bool is_active(void);

public:
	ClapTrap(std::string const& name);
	virtual ~ClapTrap();
	ClapTrap(ClapTrap const& other);
	ClapTrap &operator=(ClapTrap const& other);

	std::string const& getName() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getAttackDamage() const;

	void attack(std::string const& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
