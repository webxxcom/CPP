#include "PmergeMe.hpp"

static inline void print(std::vector<int> arr, char m)
{
    std::cout << m << ": ";
    for(int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

template <typename Container>
inline void PmergeMe::sort(Container &cont)
{
    n_cmp = 0;
    return (__internal_sort(cont, 1));
}

template <typename Container>
inline void PmergeMe::__internal_sort(Container &cont, int const pair_level)
{
    const int chunk_n = cont.size() / pair_level;
    if (chunk_n < 2)
        return ;
    const bool is_odd = chunk_n % 2;

    const int last = pair_level * chunk_n - (is_odd * pair_level);
    const int jump = pair_level * 2;
    for(int i = 0; i < last; i += jump)
    {
        int &this_pair = cont[i + pair_level - 1];
        int &next_pair = cont[i + pair_level * 2 - 1];

        if (__comp(next_pair, this_pair))
            std::swap(this_pair, next_pair);
    }
    __internal_sort(cont, pair_level * 2);

    std::vector<int> mchain;
    std::vector<int> pchain;

    // Insert b1 and a1 in the main chain
    mchain.push_back(cont[pair_level - 1]);
    mchain.push_back(cont[pair_level * 2 - 1]);

    // insert b_n into pending chain and a_n into main chain
    for(int i = 4; i <= chunk_n; i += 2)
    {
        mchain.push_back(cont[pair_level * i - 1]);
        pchain.push_back(cont[pair_level * (i - 1) - 1]);
    }
    // If an odd element was left out insert it into pending
    if (is_odd)
        pchain.push_back(cont.back());

    for (size_t i = 0; i < pchain.size(); ++i)
    {
        mchain.insert(
            std::upper_bound(mchain.begin(), mchain.end(), pchain[i], __comp),
            pchain[i]);
    }

    std::copy(mchain.begin(), mchain.end(), cont.begin());
    print(mchain, 'M');
}