/* --- Character.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/30/2025
------------------------------------------ */

#pragma once

#include "ICharacter.h"
#include "Trash.h"

class Character : public ICharacter
{
private:
    void initInventory();
    
    static const int MAX_INVITEMS = 4;
    static Trash trash;
    
    std::string name;
    AMateria *inventory[4];
public:
    Character();
    explicit Character(std::string const& name);
    Character(Character const& other);
    ~Character();

    Character &operator=(Character const& other);

    virtual std::string const &getName() const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter &target);
};
