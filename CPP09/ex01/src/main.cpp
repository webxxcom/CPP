#include <algorithm>
#include <string>
#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error! Program must take only one argument";
        return 1;
    }
    RPN rpn;

    std::cout << "Result is: " << rpn.calculate(argv[1]) << std::endl;
    return 0;
}
