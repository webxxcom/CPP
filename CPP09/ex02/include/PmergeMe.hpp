#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>
#include <memory>

class PmergeMe {
private:
    static int jacobsthal_number(size_t n);

    template<typename T>
    static inline void swap_pairs(T end, int pair_level)
    {
        T begin = end - (pair_level - 1);
        T next_begin = begin + pair_level;

        while (begin != end + 1)
        {
            std::iter_swap(begin, next_begin);
            std::advance(next_begin, 1);
            std::advance(begin, 1);
        }
    }

    template<typename T>
    static inline bool iter_compare(T it1, T it2)
    {
        ++n_compares;
        return *it1 < *it2;
    }

    template<template<typename, typename> class C, typename T, typename A>
    static void internal_sort(C<T, A> &cont, ssize_t const pair_level = 1)
    {
        typedef C<T, A> Container;
        typedef typename Container::iterator Iterator;
        typedef C<Iterator, std::allocator<Iterator> > Chain;

        const ssize_t chunk_n = cont.size() / pair_level;
        if (chunk_n < 2)
            return ;
        const int is_odd = chunk_n % 2;

        ssize_t jump = pair_level * 2;
        for(ssize_t i = 0; i < pair_level * chunk_n - (is_odd * pair_level); i += jump)
        {
            Iterator this_pair = cont.begin() + (i + pair_level - 1);
            Iterator next_pair = cont.begin() + (i + pair_level * 2 - 1);

            if (iter_compare(next_pair, this_pair))
                swap_pairs(this_pair, pair_level);
        }
        internal_sort(cont, pair_level * 2);

        Chain mchain;
        Chain pchain;

        mchain.push_back(cont.begin() + (pair_level - 1));
        mchain.push_back(cont.begin() + (pair_level * 2 - 1));

        for(ssize_t i = 4; i <= chunk_n; i += 2)
        {
            mchain.push_back(cont.begin() + (pair_level * i - 1));
            pchain.push_back(cont.begin() + (pair_level * (i - 1) - 1));
        }
        if (is_odd)
            pchain.push_back(cont.begin() + (pair_level * chunk_n - 1));

        ssize_t prev_jacobsthal = jacobsthal_number(1);
        ssize_t inserted_numbers = 0;
        for (ssize_t k = 2;; k++)
        {
            ssize_t curr_jacobsthal = jacobsthal_number(k);
            ssize_t jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
            ssize_t offset = 0;
            if (jacobsthal_diff > (int)pchain.size())
                break;
            typename Chain::iterator bound_it = mchain.begin() + (curr_jacobsthal + inserted_numbers);
            for (ssize_t n = jacobsthal_diff - 1; n >= 0; --n)
            {
                typename Chain::iterator inserted = mchain.insert(
                    std::upper_bound(mchain.begin(), bound_it, pchain[n], iter_compare<Iterator>),
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
            typename Chain::iterator curr_bound = mchain.begin() + (mchain.size() - pchain.size() + i + is_odd);
            mchain.insert(
                std::upper_bound(mchain.begin(), curr_bound, pchain[i], iter_compare<Iterator>),
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
        internal_sort(cont);
    }
};
