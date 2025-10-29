/* --- DiamondTrap.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 10/29/2025
------------------------------------------ */

#include "DiamondTrap.h"

DiamondTrap::DiamondTrap(std::string const& name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name),  name(name)
{
    std::cout << "DiamondTrap " << this->name << " constructor called" << std::endl;
    this->hit_points = FragTrap::hit_points;
    this->energy_points = ScavTrap::energy_points;
    this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other)
    : ClapTrap(other.name + "_clap_name"), FragTrap(other.name), ScavTrap(other.name)
{
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->attack_damage = other.attack_damage;
    this->energy_points = other.energy_points;
    return (*this);
}

void DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is: " << this->name << ", ClapTrap name is: " << ClapTrap::name << std::endl;
}
