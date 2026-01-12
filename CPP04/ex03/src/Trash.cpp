/* --- Trash.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 1/12/2026
------------------------------------------ */

#include "Trash.h"

void Trash::init()
{
    for(size_t i = 0; i < CAPACITY; ++i)
		this->data[i] = NULL;
    count = 0;
}

Trash::Trash() { init(); }
Trash::Trash(Trash const &other) { *this = other; }

void Trash::add(AMateria *ptr)
{
	if (!ptr)
	    return ;

	for(size_t i = 0; i < count; ++i)
		if (data[i] == ptr)
			return ;
	data[count++] = ptr;
}

void Trash::clean()
{
	for(; count > 0; --count)
		delete data[count - 1];
}

Trash::~Trash()
{
	clean();
}

Trash &Trash::operator=(Trash const &other)
{
    clean();
    init();
    while(count < other.count)
    {
        data[count] = other.data[count];
        ++count;
    }
    return (*this);
}
