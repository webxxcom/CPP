/* --- PmergeMe.cpp --- */

/* ------------------------------------------
author: undefined
date: 2/24/2026
------------------------------------------ */

#include "PmergeMe.hpp"

size_t PmergeMe::n_cmp = 0;

PmergeMe::PmergeMe() { }
PmergeMe::~PmergeMe() { }
PmergeMe::PmergeMe(PmergeMe const &other) { *this = other; }

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
    return *this;
}

bool PmergeMe::__comp(int a, int b)
{
    ++n_cmp;
    return (a < b);
}

size_t PmergeMe::__comp_number() { return n_cmp; }
