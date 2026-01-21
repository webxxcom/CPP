/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webxxcom <webxxcom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:51:10 by webxxcom          #+#    #+#             */
/*   Updated: 2026/01/21 21:12:43 by webxxcom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <exception>
#include "easyfind.h"

int main()
{
    // ---------- VECTOR TEST ----------
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "--- Vector Tests ---\n";
    try {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found 20: " << *it << std::endl;
        *it = 25; // modify element through iterator
        std::cout << "Modified element: " << vec[1] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 99);
        std::cout << "Found 99: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Not found (vector): " << e.what() << std::endl;
    }

    // Const vector
    const std::vector<int> cvec(vec);
    try {
        std::vector<int>::const_iterator it = easyfind(cvec, 25);
        std::cout << "Found 25 in const vector: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error (const vector): " << e.what() << std::endl;
    }

    // ---------- LIST TEST ----------
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);

    std::cout << "--- List Tests ---\n";
    try {
        std::list<int>::iterator it = easyfind(lst, 15);
        std::cout << "Found 15: " << *it << std::endl;
        *it = 18; // modify element
        std::cout << "Modified element: ";
        for (std::list<int>::iterator jt = lst.begin(); jt != lst.end(); ++jt)
            std::cout << *jt << " ";
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "Found 100: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Not found (list): " << e.what() << std::endl;
    }

    const std::list<int> clst(lst);
    try {
        std::list<int>::const_iterator it = easyfind(clst, 18);
        std::cout << "Found 18 in const list: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error (const list): " << e.what() << std::endl;
    }

    // ---------- DEQUE TEST ----------
    std::deque<int> deq;
    for (int i = 1; i <= 5; ++i)
        deq.push_back(i);

    std::cout << "--- Deque Tests ---\n";
    try {
        std::deque<int>::iterator it = easyfind(deq, 3);
        std::cout << "Found 3: " << *it << std::endl;
        *it = 33;
        std::cout << "Modified deque: ";
        for (std::deque<int>::iterator jt = deq.begin(); jt != deq.end(); ++jt)
            std::cout << *jt << " ";
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::deque<int>::iterator it = easyfind(deq, 99);
        std::cout << "Found 99: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Not found (deque): " << e.what() << std::endl;
    }

    const std::deque<int> cdeq(deq);
    try {
        std::deque<int>::const_iterator it = easyfind(cdeq, 33);
        std::cout << "Found 33 in const deque: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error (const deque): " << e.what() << std::endl;
    }

    // ---------- EDGE CASES ----------
    std::vector<int> emptyVec;
    std::cout << "--- Edge Cases ---\n";
    try {
        std::vector<int>::iterator it = easyfind(emptyVec, 1);
        std::cout << "Found in empty vector: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Empty vector: " << e.what() << std::endl;
    }

    std::vector<int> single;
    single.push_back(42);
    try {
        std::vector<int>::iterator it = easyfind(single, 42);
        std::cout << "Found single element: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error (single element): " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(single, 43);
        std::cout << "Found single element: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Not found (single element): " << e.what() << std::endl;
    }

    return 0;
}
