/* --- Character.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "Character.h"
#include <iostream>

Trash Character::trash;

void Character::initInventory()
{
	for(size_t i = 0; i < MAX_INVITEMS; ++i)
		this->inventory[i] = NULL;
}

Character::Character()
    : name()
{
	initInventory();
}

Character::Character(std::string const &name)
	: name(name)
{
	initInventory();
}

Character::Character(Character const &other)
	: name()
{
	initInventory();
	*this = other;
}

Character::~Character()
{
	std::cout << "Called destructor for " << this->name << '\n';
	for(size_t i = 0; i < MAX_INVITEMS; ++i)
		trash.add(this->inventory[i]);
	trash.clean();
}

Character &Character::operator=(Character const &other)
{
    if (this != &other)
	{
		this->name = name;
		for(int i = 0; i < MAX_INVITEMS; ++i)
		{
			delete this->inventory[i];
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
		}
	}
	return *this;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for(size_t i = 0; i < MAX_INVITEMS; ++i)
	{
		if (!inventory[i])
		{
			std::cout << "Equppied " << m << '\n';
			inventory[i] = m;
			return ;
		}
	}
	trash.add(m);
}

void Character::unequip(int idx)
{
	if (idx < 0 ||idx >= MAX_INVITEMS || !inventory[idx])
		return ;
	std::cout << "Unequiped " << inventory[idx] << '\n';
	trash.add(inventory[idx]);
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < MAX_INVITEMS && inventory[idx])
		inventory[idx]->use(target);
}

std::string const &Character::getName() const
{
	return this->name;
}
