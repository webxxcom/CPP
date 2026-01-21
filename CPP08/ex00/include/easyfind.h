/* --- easyfind.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/21/2026
------------------------------------------ */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &arr, int num)
{
    typename T::iterator begin = arr.begin();
    typename T::iterator end = arr.end();

    typename T::iterator found = std::find(begin, end, num);
    if (end == found)
        throw std::domain_error("The value is absent in the container");
    return found;
}

template<typename T>
typename T::const_iterator easyfind(T const& arr, int num)
{
    typename T::const_iterator begin = arr.begin();
    typename T::const_iterator end = arr.end();

    typename T::const_iterator found = std::find(begin, end, num);
    if (end == found)
        throw std::domain_error("The value is absent in the container");
    return found;
}

#endif // EASYFIND_H
