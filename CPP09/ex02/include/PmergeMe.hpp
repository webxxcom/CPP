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

static inline void print(std::vector<int> arr, char m)
{
    std::cout << m << ": ";
    for(int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

template<typename T>
static T advnce(T iter, int step)
{
    std::advance(iter, step);
    return (iter);
}


class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    template<typename Container>
    static void __internal_sort(Container &cont, int const pair_level)
    {
        const int chunk_n = cont.size() / pair_level;
        if (chunk_n < 2)
            return ;
        const int is_odd = cont.size() % 2;

        int jump = pair_level * 2;
        for(int i = 0; i < pair_level * chunk_n - (is_odd * pair_level); i += jump)
        {
            int &this_pair = cont[i + pair_level - 1];
            int &next_pair = cont[i + pair_level * 2 - 1];

            if (this_pair > next_pair)
                std::swap(this_pair, next_pair);
        }
        __internal_sort(cont, pair_level * 2);
        if (pair_level > 1)
            return ;

        std::vector<int> mchain;
        std::vector<int> pchain;

        mchain.push_back(cont[pair_level - 1]);
        mchain.push_back(cont[pair_level * 2 - 1]);

        for(int i = 4; i <= chunk_n; i += 2)
        {
            mchain.push_back(cont[pair_level * i - 1]);
            pchain.push_back(cont[pair_level * (i - 1) - 1]);
        }
        if (is_odd)
            pchain.push_back(cont.back());

        for (size_t i = 0; i < pchain.size(); ++i)
        {
            mchain.insert(
                std::upper_bound(mchain.begin(), mchain.end(), pchain[i]),
                pchain[i]);
        }

        std::copy(mchain.begin(), mchain.end(), cont.begin());
        print(mchain, 'M');
    }

    template<typename Container>
    static void sort(Container &cont)
    {
        return (__internal_sort(cont, 1));
    }
private:

};
