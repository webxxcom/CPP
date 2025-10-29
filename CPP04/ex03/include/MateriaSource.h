/* --- MaterialSource.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 9/30/2025
------------------------------------------ */

#pragma once

#include "IMateriaSource.h"
#include "AMateria.h"

class MateriaSource : public IMateriaSource
{
private:
    static const int MAX_MATERIA = 4;
    AMateria *learntMaterias[MAX_MATERIA];
public:
    MateriaSource();
    virtual ~MateriaSource();
    virtual void learnMateria(AMateria *materia);
    virtual AMateria *createMateria(std::string const &type);
};
