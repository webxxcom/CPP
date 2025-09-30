/* --- Character.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "Character.h"

Character::Character()
	: name()
{
	for(int i = 0; i < MAX_INVITEMS; ++i)
		this->inventory[i] = NULL;
}

Character::Character(std::string const &name)
	: name(name)
{
	for (int i = 0; i < MAX_INVITEMS; ++i)
		this->inventory[i] = NULL;
}

Character::Character(Character const &other)
{
	*this = other;
}

Character::~Character()
{
}

Character &Character::operator=(Character const &other)
{
    if (this != &other)
	{
		this->name = name;
		for(int i = 0; i < MAX_INVITEMS; ++i)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = other.inventory[i];
		}
	}
	return *this;
}

void Character::equip(AMateria *m)
{
	for(int i = 0; i < MAX_INVITEMS; ++i)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_INVITEMS)
		return ;
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= MAX_INVITEMS)
		return ;
	if (inventory[idx])
		inventory[idx]->use(target);
}

std::string const &Character::getName() const
{
	return this->name;
}
