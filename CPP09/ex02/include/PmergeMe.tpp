#include "PmergeMe.hpp"

static inline void print(std::vector<int> arr, char m)
{
    std::cout << m << ": ";
    for(int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}
static inline void print(std::vector<std::vector<int>::iterator> arr, char m)
{
    std::cout << m << ": ";
    for(int i = 0; i < arr.size(); ++i)
    {
        std::cout << (*arr[i]) << ' ';
    }
    std::cout << std::endl;
}
template <typename Container>
inline void PmergeMe::sort(Container &cont)
{
    n_cmp = 0;
    return (__internal_sort(cont, 1));
}

template <typename Iter>
inline void PmergeMe::__swap_pair(Iter ths, int pair_level)
{
    Iter start = ths + (-pair_level + 1);
    Iter end = ths + 1;
    while (start != end)
    {
        std::iter_swap(start, start + pair_level);
        std::advance(start, 1); 
    }
}

template <typename It>
static bool __comp_iter(It it1, It it2)
{
    return *it1 < *it2;
}

template <typename Container>
inline void PmergeMe::__internal_sort(Container &cont, int const pair_level)
{
    typedef typename Container::iterator Iterator;

    const int chunk_n = cont.size() / pair_level;
    if (chunk_n < 2)
        return ;
    const bool is_odd = chunk_n % 2;

    const int last = pair_level * chunk_n - (is_odd * pair_level);
    const int jump = pair_level * 2;
    for(int i = 0; i < last; i += jump)
    {
        Iterator this_pair = cont.begin() + i + pair_level - 1;
        Iterator next_pair = this_pair + pair_level;

        if (__comp(*next_pair, *this_pair))
            __swap_pair(this_pair, pair_level);
    }
    __internal_sort(cont, pair_level * 2);

    std::vector<Iterator> mchain;
    std::vector<Iterator> pchain;

    mchain.push_back(cont.begin() + pair_level - 1);
    mchain.push_back(mchain[0] + pair_level);

    int i;
    for(i = 3; i + 1 < chunk_n; i += 2)
    {
        pchain.push_back(cont.begin() + pair_level * i - 1);
        mchain.push_back(cont.begin() + pair_level * (i + 1) - 1);
    }
    if (i <= chunk_n)
        pchain.push_back(cont.begin() + pair_level * i - 1);

    for (i = 0; i < pchain.size(); ++i)
    {
        Iterator val = pchain[i];
        typename std::vector<Iterator>::iterator bound = std::upper_bound(mchain.begin(), mchain.end(), val, __comp_iter<Iterator>);

        mchain.insert(bound, *(pchain.begin() + i));
    }
    std::vector<int> cp(cont);
    for (i = 0; i < mchain.size(); ++i)
    {
        Iterator begin = mchain[i] + (-pair_level + 1);
        Iterator end = mchain[i] + 1;

        std::copy(begin, end, cp.begin() + pair_level * i);
    }
    cont = cp;
}