/* --- Trash.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/12/2026
------------------------------------------ */

#ifndef TRASH_H
#define TRASH_H

#include "AMateria.h"

class Trash
{
private:
    static size_t const CAPACITY = 256;
    AMateria *data[CAPACITY];
    size_t count;

    void init();
public:
    void add(AMateria *ptr);
    void clean();

    Trash();
    Trash(Trash const &other);
    ~Trash();
    Trash &operator=(Trash const &other);
};

#endif // TRASH_H
