/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webxxcom <webxxcom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:33:12 by webxxcom          #+#    #+#             */
/*   Updated: 2026/01/23 19:38:51 by webxxcom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <vector>
#include <sys/time.h>
#include <deque>
#include <cerrno>
#include <limits>
#include <cstdlib>

#include "PmergeMe.hpp"

template<typename Cont>
static inline void print(Cont arr)
{
    for(size_t i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i];
        if (i + 1 >= arr.size())
            break;
        std::cout << ' ';
    }
}

// Current time in microseconds
long getTime()
{
    timeval tv;
    gettimeofday(&tv, NULL);

    return tv.tv_sec * 1000000L + tv.tv_usec;
}

static bool validate_arg(std::string const &arg)
{
    // strtol would accept "12abc", "+5" and " 5"
    if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
        return false;

    errno = 0;
    long nbr = std::strtol(arg.c_str(), NULL, 10);
    return errno != ERANGE && nbr <= std::numeric_limits<int>::max();
}

std::deque<int> makeDeque(std::vector<int> const& vec)
{
    std::deque<int> res;

    res.insert(res.end(), vec.begin(), vec.end());
    return res;
}

template<typename Cont>
static bool is_sorted(Cont const& nums)
{
    return std::adjacent_find(nums.begin(), nums.end(), std::greater<int>()) == nums.end();
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "Usage: " << argv[0] << " <list of numbers>" << std::endl;
        return 1;
    }
    
    std::vector<int> a;
    for (int i = 1; i < argc; ++i)
    {
        if (validate_arg(argv[i]))
            a.push_back(std::atoi(argv[i]));
        else
        {
            std::cerr << "Error: Invalid number: " << argv[i] << std::endl;
            return 1;
        }
    }

    std::cout << "Before: ";
    print(a);
    std::cout << '\n';

    // vector sorting
    long start = getTime();
    std::vector<int> sortedVec = a;
    PmergeMe::sort(sortedVec);
    long end = getTime();
    std::cout << "After: ";
    print(sortedVec);
    std::cout << '\n';

    if (!is_sorted(sortedVec))
    {
        std::cerr << "The sequence for std::vector was not sorted" << std::endl;
        return 1;
    }
    std::cout << "Time to process a range of " << a.size() << " elements with std::vector: " << (end - start) << " us\n";

    // deque sorting
    PmergeMe::n_compares = 0;
    start = getTime();
    std::deque<int> sortedDeque = makeDeque(a);
    PmergeMe::sort(sortedDeque);
    end = getTime();

    if (!is_sorted(sortedDeque))
    {
        std::cerr << "The sequence for std::deque was not sorted" << std::endl;
        return 1;
    }
    std::cout << "Time to process a range of " << a.size() << " elements with std::deque: " << (end - start) << " us\n";
    
    std::cout << "Number of comparisons: " << PmergeMe::n_compares << std::endl;
}
