/* --- MaterialSource.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 9/30/2025
------------------------------------------ */

#include "MateriaSource.h"

MateriaSource::MateriaSource()
{
    for(size_t i = 0; i < MAX_MATERIA; ++i)
        this->learntMaterias[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for(size_t i = 0; i < MAX_MATERIA; ++i)
        delete this->learntMaterias[i];
}

void MateriaSource::learnMateria(AMateria *materia)
{
    for(int i = 0; i < MAX_MATERIA; ++i)
    {
        if (!this->learntMaterias[i])
        {
            this->learntMaterias[i] = materia;
            return ;
        }
    }
    delete materia; // Materia cannot be learnt because array is full
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
