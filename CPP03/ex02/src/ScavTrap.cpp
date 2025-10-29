/* --- ScavTrap.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 10/29/2025
------------------------------------------ */

#include "ScavTrap.h"

ScavTrap::ScavTrap(std::string const& name)
    : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap " << this->name << " initialized" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap desstructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other)
    : ClapTrap(other.name, other.hit_points, other.energy_points, other.attack_damage)
{
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->hit_points == 0 || this->energy_points == 0)
        return ;
    --this->energy_points;
    std::cout << "ScavTrap " << this->name
        << " attacks " << target
        << ", causing " << this->attack_damage << " points of damage" << std::endl;
}

void ScavTrap::guardGate()
{
    if (this->hit_points == 0 || this->energy_points == 0)
        return ;
    std::cout << "ScavTrap is in gate-keeping mode" << std::endl;
}
