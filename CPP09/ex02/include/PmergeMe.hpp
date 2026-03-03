/* --- PmergeMe.h --- */

/* ------------------------------------------
Author: undefined
Date: 2/24/2026
------------------------------------------ */

#pragma once

#include <vector>
#include <stdexcept>
#include <utility>
#include <iostream>
#include <algorithm>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(PmergeMe const& other);
    PmergeMe &operator=(PmergeMe const& other);
    ~PmergeMe();

    template<typename Container>
    void sort(Container &cont);

    static size_t __comp_number();
private:
    static size_t n_cmp;

    static bool __comp(int a, int b);

    template<typename Container>
    static void __internal_sort(Container &cont, int const pair_level);
};

#include "PmergeMe.tpp"