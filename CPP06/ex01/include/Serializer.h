/* --- Serializer.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/17/2026
------------------------------------------ */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include <stdint.h>

class Data;

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
private:
    Serializer();
    ~Serializer();

};

#endif // SERIALIZER_H
