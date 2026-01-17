/* --- Serializer.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 1/17/2026
------------------------------------------ */

#include "Serializer.h"
#include "Data.h"

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
