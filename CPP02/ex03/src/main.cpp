#include <iostream>
#include "Fixed.h"

int main(void)
{
    Fixed a;                                    // default = 0
    Fixed b(Fixed(5.05f) * Fixed(2));           // 5.05 * 2 = 10.1

    std::cout << "a = " << a << std::endl;      // 0
    std::cout << "++a = " << ++a << std::endl;  // 0 -> 0.00390625
    std::cout << "a = " << a << std::endl;      // 0.00390625
    std::cout << "a++ = " << a++ << std::endl;  // prints 0.00390625, then a=0.0078125
    std::cout << "a = " << a << std::endl;      // 0.0078125

    std::cout << "a + a = " << (a + a) << std::endl; // 0.0078125 + 0.0078125 = 0.015625
    std::cout << "a - b = " << (a - b) << std::endl; // 0.0078125 - 10.1 = -10.0921875
    std::cout << "b * a = " << (b * a) << std::endl; // 10.1 * 0.0078125 = 0.07890625
    std::cout << "b / a = " << (b / a) << std::endl; // 10.1 / 0.0078125 = 1292.5

    std::cout << "b = " << b << std::endl;                                // 10.1
    std::cout << "10.2 / 2 = " << (Fixed(10.2f) / Fixed(2)) << std::endl; // 5.1

    // Comparisons
    std::cout << std::boolalpha;
    std::cout << "a < b  = " << (a < b) << std::endl;  // 2 < 10.1 → true
    std::cout << "a > b  = " << (a > b) << std::endl;  // 2 > 10.1 → false
    std::cout << "a <= b = " << (a <= b) << std::endl; // true
    std::cout << "a >= b = " << (a >= b) << std::endl; // false
    std::cout << "a == b = " << (a == b) << std::endl; // false
    std::cout << "a != b = " << (a != b) << std::endl; // true

    // Static min/max
    std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl; // 10.1
    std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl; // 0.0078125

    return 0;
}
