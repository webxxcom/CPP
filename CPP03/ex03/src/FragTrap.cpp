/* --- FragTrap.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 10/29/2025
------------------------------------------ */

#include "FragTrap.h"

FragTrap::FragTrap(std::string const &name)
    : ClapTrap(name)
{
    std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other)
    : ClapTrap(other.name)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    return *this;
}

void FragTrap::attack(std::string const &target)
{
    if (this->is_active())
    {
        --this->energy_points;
        std::cout << "FragTrap " << this->name
            << " attacks " << target
            << ", causing " << this->attack_damage << " points of damage" << std::endl;
    }
    else
        std::cout << "FragTrap " << this->name << " cannot attack" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (this->is_active())
        std::cout << "DO YOU GUYS WANT TO HIGH FIVE????" << std::endl;
}
