/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkravche <rkravche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:33:12 by webxxcom          #+#    #+#             */
/*   Updated: 2026/01/20 17:44:18 by rkravche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Array.h"

#define SEP std::cout << "-----------------------------\n";

int main()
{
    std::cout << "===== TEST 1: Default constructor =====\n";
    Array<int> empty;
    std::cout << "Size: " << empty.size() << std::endl;
    SEP

    std::cout << "===== TEST 2: Sized constructor =====\n";
    Array<int> a(5);
    std::cout << "Size: " << a.size() << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    SEP

    std::cout << "===== TEST 3: Write / read access =====\n";
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i * 10;
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    SEP

    std::cout << "===== TEST 4: Copy constructor =====\n";
    Array<int> b(a);
    b[0] = 999;
    std::cout << "Original a[0]: " << a[0] << std::endl;
    std::cout << "Copy     b[0]: " << b[0] << std::endl;
    SEP

    std::cout << "===== TEST 5: Assignment operator =====\n";
    Array<int> c;
    c = a;
    c[1] = 888;
    std::cout << "Original a[1]: " << a[1] << std::endl;
    std::cout << "Assigned c[1]: " << c[1] << std::endl;
    SEP

    std::cout << "===== TEST 6: Out-of-bounds access =====\n";
    try
    {
        std::cout << a[100] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    SEP

    std::cout << "===== TEST 7: Array of strings =====\n";
    Array<std::string> s(3);
    s[0] = "hello";
    s[1] = "world";
    s[2] = "array";
    for (unsigned int i = 0; i < s.size(); i++)
        std::cout << "s[" << i << "] = " << s[i] << std::endl;
    SEP

    std::cout << "===== TEST 8: Const array access =====\n";
    const Array<int> ca(a);
    std::cout << "ca[2] = " << ca[2] << std::endl;
    SEP

    std::cout << "===== ALL TESTS DONE =====\n";
    return 0;
}
