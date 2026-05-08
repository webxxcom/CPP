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
#include "PmergeMe.hpp"
#include <sys/time.h>
#include <list>
#include <deque>
#include <cerrno>
#include <limits>

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

double getTime()
{
    timeval tv;
    gettimeofday(&tv, NULL);

    return tv.tv_sec + tv.tv_usec * 0.000001;
}

static bool validate_arg(std::string arg)
{
    if (arg[0] == '-')
    {
        std::cerr << "Negative numbers are not allowed" << std::endl;
        return false;
    }
    long nbr = strtol(arg.c_str(), NULL, 10);
    if (nbr == 0 && arg != "0")
    {
        std::cerr << "Non-number arguments not allowed" << std::endl;
        return false;
    }
    if (nbr > std::numeric_limits<int>::max() || errno == ERANGE)
    {
        std::cerr << "Too big arguments are not allowed" << std::endl;
        return false;
    }
    return true;
}

static std::vector<int> parse_args(char **argv, int n)
{
    std::vector<int> res;

    for (int i = 0; i < n; ++i)
        if (validate_arg(argv[i]))
            res.push_back(std::atoi(argv[i]));
    return res;
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
    for(size_t i = 0; i + 1 < nums.size(); ++i)
    {
        if (nums[i] > nums[i + 1])
        {
            std::cout << "ERROR: " << nums[i] << " " << nums[i + 1] << " pos: " << i << '\n';
            break;
        }
    }
    return std::adjacent_find(nums.begin(), nums.end(), std::greater<int>()) == nums.end();
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "Usage: " << argv[0] << " <list of numbers>" << std::endl;
        return 1;
    }
    std::vector<int> a = parse_args(argv + 1, argc - 1);

    std::cout << "Before:\t[";
    print(a);
    std::cout << "]\n";

    // vector sorting
    std::vector<int> sortedVec = a;
    
    double start = getTime();
    PmergeMe::sort(sortedVec);
    double end = getTime();
    std::cout << "After:\t[";
    print(sortedVec);
    std::cout << "]\n";

    if (!is_sorted(sortedVec))
    {
        std::cerr << "The sequence for std::vector was not sorted" << std::endl;
        return 1;
    }

    std::cout << "Time to process a range of " << a.size() << " elements with std::vector: " << (end - start) << '\n';

    //list sorting
    std::deque<int> sortedDeque = makeDeque(a);
    start = getTime();
    PmergeMe::sort(sortedDeque);
    end = getTime();

    if (!is_sorted(sortedDeque))
    {
        std::cerr << "The sequence for std::deque was not sorted" << std::endl;
        return 1;
    }

    std::cout << "Time to process a range of " << a.size() << " elements with std::deque: " << (end - start) << '\n';
    
    std::cout << "Number of comparisons: " << PmergeMe::n_compares << std::endl;
}
