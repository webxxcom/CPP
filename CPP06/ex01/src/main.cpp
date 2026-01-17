/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webxxcom <webxxcom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:25:27 by webxxcom          #+#    #+#             */
/*   Updated: 2026/01/17 17:29:03 by webxxcom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.h"
#include "Serializer.h"
#include <iostream>

int main()
{
    std::cout << "===== SERIALIZATION TESTS =====\n";

    Data d;
    d.setNum(42);
    d.setName("Hello");

    std::cout << "Original Data object address: " << &d << std::endl;

    // Serialize
    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

    // Deserialize
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << ptr << std::endl;

    // Check if the pointer matches the original
    if (ptr == &d)
        std::cout << "SUCCESS: deserialized pointer matches original\n";
    else
        std::cout << "FAIL: deserialized pointer does NOT match original\n";

    // Optional: Check that data members are intact
    std::cout << "Deserialized Data content: num = " << ptr->getNum()
              << ", name = \"" << ptr->getName() << "\"\n";

    return 0;
}