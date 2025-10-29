/* --- Character.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "Character.h"

void Character::initInventory()
{
	for(size_t i = 0; i < MAX_INVITEMS; ++i)
		this->inventory[i] = NULL;
}


Character::Character()
    : name(), trashCount(0)
{
	initInventory();
}

Character::Character(std::string const &name)
	: name(name), trashCount(0)
{
	initInventory();
}

Character::Character(Character const &other)
	: name(), trashCount(0)
{
	initInventory();
	*this = other;
}

Character::~Character()
{
	for(size_t i = 0; i < MAX_INVITEMS; ++i)
		delete this->inventory[i];
	for(int i = 0; i < trashCount; ++i)
		delete trash[i];
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
			inventory[i] = m;
			return ;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 ||idx >= MAX_INVITEMS || !inventory[idx])
		return ;
	trash[trashCount++] = inventory[idx];
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
