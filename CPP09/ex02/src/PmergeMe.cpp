/* --- PmergeMe.cpp --- */

/* ------------------------------------------
author: undefined
date: 2/24/2026
------------------------------------------ */

#include "PmergeMe.hpp"

size_t PmergeMe::n_compares = 0;

int PmergeMe::_jacobsthal_number(size_t n)
{
    return (int)round((pow(2, n + 1) + pow(-1, n)) / 3);
}
