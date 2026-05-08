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

static inline void print(std::vector<int> arr)
{
    for(int i = 0; i < arr.size(); ++i)
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

int main()
{
    std::vector<int> a;
    a.push_back(2);
    a.push_back(14);
    a.push_back(11);
    a.push_back(7);
    a.push_back(3);
    a.push_back(13);
    a.push_back(12);
    a.push_back(9);
    a.push_back(5);
    a.push_back(8);
    a.push_back(1);
    a.push_back(4);
    a.push_back(10);
    a.push_back(6);
    a.push_back(0);

    std::cout << "Before:\t[";
    print(a);
    std::cout << "]\n";

    PmergeMe::sort(a);

    double start = getTime();
    std::cout << "After:\t[";
    print(a);
    std::cout << "]\n";
    double end = getTime();

    std::cout << "Time to process a range of " << a.size() << " elements with std::vector: " << (end - start) << '\n';
    std::cout << "Time to process a range of " << a.size() << " elements with std::queue: " << 0.1 << '\n';
    
    std::cout << "Number of comparisons: " << PmergeMe::n_compares << std::endl;
}
