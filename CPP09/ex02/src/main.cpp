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

int main()
{
    std::vector<int> a;
    a.push_back(11);
    a.push_back(2);
    a.push_back(17);
    a.push_back(0);
    a.push_back(16);
    a.push_back(8);
    a.push_back(6);
    a.push_back(15);
    a.push_back(10);
    a.push_back(3);
    a.push_back(21);
    a.push_back(1);
    a.push_back(18);
    a.push_back(9);
    a.push_back(19);
    a.push_back(14);
    a.push_back(12);
    a.push_back(5);
    a.push_back(4);
    a.push_back(20);
    a.push_back(13);
    a.push_back(7);

    // Sort using normal sort
    std::vector<int> cpy(a);
    std::sort(cpy.begin(), cpy.end());
    
    // Sort using merge insertion
    PmergeMe().sort(a);

    print(a, 'C');
    if (cpy != a)
        std::cout << "The array was not sorted\n" << std::endl;
    else
        std::cout << "SORTED!!" << std::endl;
    std::cout << "Number of comparisons: " << PmergeMe::__comp_number() << std::endl;
}
