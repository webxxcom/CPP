/* --- ClapTrap.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 10/29/2025
------------------------------------------ */

#include "ClapTrap.h"

bool ClapTrap::is_active(void)
{
    return (this->energy_points != 0 && this->hit_points != 0);
}

ClapTrap::ClapTrap(std::string const& name)
    : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
    *this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    return *this;
}

std::string const &ClapTrap::getName() const
{
    return (this->name);
}

unsigned int ClapTrap::getHitPoints() const
{
    return (this->hit_points);
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return (this->energy_points);
}

unsigned int ClapTrap::getAttackDamage() const
{
    return (this->attack_damage);
}

void ClapTrap::attack(std::string const& target)
{
    if (this->is_active())
    {
        --this->energy_points;
        std::cout << "ClapTrap " << this->name
            << " attacks " << target
            << ", causing " << this->attack_damage << " points of damage" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " cannot attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->hit_points = (this->hit_points < amount) ? 0 : this->hit_points - amount;
    std::cout << "ClapTrap " << this->name << " was damaged by " << amount << " hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_points == 0)
        return ;
    --this->energy_points;
    this->hit_points += amount;
    std::cout << "ClapTrap " << this->name << " was repaired by " << amount << " points" << std::endl;
}
