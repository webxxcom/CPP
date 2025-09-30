/* --- MaterialSource.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "MateriaSource.h"

void MateriaSource::learnMateria(AMateria *materia)
{
    for(int i = 0; i < MAX_MATERIA; ++i)
    {
        if (!this->learntMaterias[i])
        {
            this->learntMaterias[i] = materia;
            break ;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for(int i = 0; i < MAX_MATERIA; ++i)
    {
        if (this->learntMaterias[i]->getType() == type)
            return this->learntMaterias[i]->clone();
    }
    return (NULL);
}
