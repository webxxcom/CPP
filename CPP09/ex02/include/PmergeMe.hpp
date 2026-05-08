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

template<typename Iter>
static inline void swap_iters(Iter end, int pair_level)
{
    Iter begin = end - (pair_level - 1);
    Iter next_begin = begin + pair_level;

    while (begin != end + 1)
    {
        std::iter_swap(begin, next_begin);
        std::advance(next_begin, 1);
        std::advance(begin, 1);
    }
}

class PmergeMe {
public:
    static size_t n_compares;

    PmergeMe();
    ~PmergeMe();

    template<typename Iter>
    static inline bool compare(Iter it1, Iter it2)
    {
        ++n_compares;
        return *it1 < *it2;
    }

    template<typename Container>
    static void __internal_sort(Container &cont, int const pair_level = 1)
    {
        typedef typename Container::iterator Iterator;

        const int chunk_n = cont.size() / pair_level;
        if (chunk_n < 2)
            return ;
        const int is_odd = chunk_n % 2;

        int jump = pair_level * 2;
        for(int i = 0; i < pair_level * chunk_n - (is_odd * pair_level); i += jump)
        {
            Iterator this_pair = cont.begin() + (i + pair_level - 1);
            Iterator next_pair = cont.begin() + (i + pair_level * 2 - 1);

            if (compare(next_pair, this_pair))
                swap_iters(this_pair, pair_level);
        }
        __internal_sort(cont, pair_level * 2);

        std::vector<Iterator> mchain;
        std::vector<Iterator> pchain;

        mchain.push_back(cont.begin() + (pair_level - 1));
        mchain.push_back(cont.begin() + (pair_level * 2 - 1));

        for(int i = 4; i <= chunk_n; i += 2)
        {
            mchain.push_back(cont.begin() + (pair_level * i - 1));
            pchain.push_back(cont.begin() + (pair_level * (i - 1) - 1));
        }
        if (is_odd)
            pchain.push_back(cont.begin() + (pair_level * chunk_n - 1));

        for (size_t i = 0; i < pchain.size(); ++i)
        {
            mchain.insert(
                std::upper_bound(mchain.begin(), mchain.end(), pchain[i], compare<Iterator>),
                pchain[i]);
        }

        std::vector<int> res;
        for (size_t i = 0; i < mchain.size(); ++i)
        {
            Iterator beg = mchain[i] - (pair_level - 1);

            res.insert(res.end(), beg, mchain[i] + 1);
        }
        cont = res;
    }

    template<typename Container>
    static void sort(Container &cont)
    {
        return (__internal_sort(cont));
    }
};
