/* --- PmergeMe.h --- */

/* ------------------------------------------
Author: undefined
Date: 2/24/2026
------------------------------------------ */

#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cmath>

class PmergeMe {
private:
    static int _jacobsthal_number(size_t n);

    template<typename Iter>
    static inline void __swap_pairs(Iter end, int pair_level)
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

    template<typename Iter>
    static inline bool __iter_compare(Iter it1, Iter it2)
    {
        ++n_compares;
        return *it1 < *it2;
    }

    template<typename Container>
    static void __internal_sort(Container &cont, ssize_t const pair_level = 1)
    {
        typedef typename Container::iterator Iterator;

        const ssize_t chunk_n = cont.size() / pair_level;
        if (chunk_n < 2)
            return ;
        const int is_odd = chunk_n % 2;

        ssize_t jump = pair_level * 2;
        for(ssize_t i = 0; i < pair_level * chunk_n - (is_odd * pair_level); i += jump)
        {
            Iterator this_pair = cont.begin() + (i + pair_level - 1);
            Iterator next_pair = cont.begin() + (i + pair_level * 2 - 1);

            if (__iter_compare(next_pair, this_pair))
                __swap_pairs(this_pair, pair_level);
        }
        __internal_sort(cont, pair_level * 2);

        std::vector<Iterator> mchain;
        std::vector<Iterator> pchain;

        mchain.push_back(cont.begin() + (pair_level - 1));
        mchain.push_back(cont.begin() + (pair_level * 2 - 1));

        for(ssize_t i = 4; i <= chunk_n; i += 2)
        {
            mchain.push_back(cont.begin() + (pair_level * i - 1));
            pchain.push_back(cont.begin() + (pair_level * (i - 1) - 1));
        }
        if (is_odd)
            pchain.push_back(cont.begin() + (pair_level * chunk_n - 1));

        ssize_t prev_jacobsthal = _jacobsthal_number(1);
        ssize_t inserted_numbers = 0;
        for (ssize_t k = 2;; k++)
        {
            ssize_t curr_jacobsthal = _jacobsthal_number(k);
            ssize_t jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
            ssize_t offset = 0;
            if (jacobsthal_diff > (int)pchain.size())
                break;
            typename std::vector<Iterator>::iterator bound_it = mchain.begin() + (curr_jacobsthal + inserted_numbers);
            for (ssize_t n = jacobsthal_diff - 1; n >= 0; --n)
            {
                typename std::vector<Iterator>::iterator inserted = mchain.insert(
                    std::upper_bound(mchain.begin(), bound_it, pchain[n], __iter_compare<Iterator>),
                    pchain[n]
                );

                offset += (inserted - mchain.begin()) == (curr_jacobsthal + inserted_numbers);
                bound_it = mchain.begin() + (curr_jacobsthal + inserted_numbers - offset);
            }
            pchain.erase(pchain.begin(), pchain.begin() + jacobsthal_diff);
            prev_jacobsthal = curr_jacobsthal;
            inserted_numbers += jacobsthal_diff;
        }

        for (ssize_t i = (ssize_t)pchain.size(); i-- > 0;)
        {
            typename std::vector<Iterator>::iterator curr_bound = mchain.begin() + (mchain.size() - pchain.size() + i + is_odd);
            mchain.insert(
                std::upper_bound(mchain.begin(), curr_bound, pchain[i], __iter_compare<Iterator>),
                pchain[i]);
        }

        Container res;
        for (size_t i = 0; i < mchain.size(); ++i)
        {
            Iterator beg = mchain[i] - (pair_level - 1);

            res.insert(res.end(), beg, mchain[i] + 1);
        }
        std::copy(res.begin(), res.end(), cont.begin());
    }

public:

    static size_t n_compares;

    template<typename Container>
    static void sort(Container &cont)
    {
        return __internal_sort(cont);
    }
};
