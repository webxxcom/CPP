/* --- RPN.h --- */

/* ------------------------------------------
Author: undefined
Date: 2/24/2026
------------------------------------------ */

#pragma once
#include <string>

class RPN {
public:
    RPN();
    RPN(RPN const& other);
    RPN& operator=(RPN const& other);
    ~RPN();

    static long long calculate(std::string const &expr);
};
