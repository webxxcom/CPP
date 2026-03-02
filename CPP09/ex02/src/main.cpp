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
    a.push_back(1);
    a.push_back(5);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(8);
    a.push_back(9);

    
    PmergeMe::sort(a);
    for(size_t i = 0; i < a.size(); ++i)
        std::cout << a[i] << " ";
}
