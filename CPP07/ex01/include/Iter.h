/* --- Iter.h --- */

/* ------------------------------------------
Author: undefined
Date: 1/20/2026
------------------------------------------ */

#ifndef ITER_H
#define ITER_H

#include <cstddef>

template<typename T>
void iter(T *arr, size_t const len, void (*foo)(T& param))
{
    for(size_t i = 0; i < len; ++i)
        foo(arr[i]);
}

#endif // ITER_H
