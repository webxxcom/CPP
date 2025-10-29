/* --- ScavTrap.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 10/29/2025
------------------------------------------ */

#include "ScavTrap.h"

ScavTrap::ScavTrap(std::string const &name)
    : ClapTrap(name)
{
    std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other)
    : ClapTrap(other.name)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    return *this;
}

void ScavTrap::attack(std::string const& target)
{
    if (this->is_active())
    {
        --this->energy_points;
        std::cout << "ScavTrap " << this->name
            << " attacks " << target
            << ", causing " << this->attack_damage << " points of damage" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->name << " cannot attack" << std::endl;
}

void ScavTrap::guardGate()
{
    if (this->is_active())
        std::cout << "ScavTrap is in gate-keeping mode" << std::endl;
    else
        std::cout << "ScavTrap " << this->name << " cannot guard gate" << std::endl;
}
