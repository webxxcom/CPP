#include "RPN.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Program must take one argument" << std::endl;
        return 1;
    }

    try
    {
        long long res = RPN::calculate(argv[1]);
        std::cout << res << std::endl;
    }
    catch(std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
