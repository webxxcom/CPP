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
	ClapTrap(std::string const& name, unsigned int hit_points, unsigned int energy_points, unsigned int attack_damage);
	ClapTrap(std::string const& name);
	virtual ~ClapTrap();
	ClapTrap(ClapTrap const& other);
	ClapTrap &operator=(ClapTrap const& other);

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
