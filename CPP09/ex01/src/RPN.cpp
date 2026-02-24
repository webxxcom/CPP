/* --- RPN.cpp --- */

/* ------------------------------------------
author: undefined
date: 2/24/2026
------------------------------------------ */

#include "RPN.hpp"
#include <queue>
#include <iostream>
#include <stack>


static bool isoperand(char ch)
{
    return (ch == '/' || ch == '*' || ch == '+' || ch == '-');
}

static void process_oper(std::stack<char> &s, char oper)
{
    int n;
    int res;

    if (s.empty())
        throw std::runtime_error("Error! Excessive operand");
    n = s.top();
    s.pop();
    if (s.empty())
        throw std::runtime_error("Error! Excessive operand");
    res = s.top();
    s.pop(); 
    switch (oper)
    {
    case '/':
        res /= n;
        break;
    case '*':
        res *= n;
        break;
    case '+':
        res += n;
        break;
    case '-':
        res -= n;
        break;
    }
    s.push(res);
}

RPN::RPN() { }
RPN::~RPN() { }

long long RPN::calculate(std::string const &expr)
{
    std::stack<char> s;

    for (size_t i = 0; i < expr.size(); ++i)
    {
        if (std::isdigit(expr[i]))
            s.push(expr[i] - '0');
        else if (isoperand(expr[i]))
            process_oper(s, expr[i]);
        else if (!std::isspace(expr[i]))
            throw std::runtime_error("Error! Unknown character occured");
    } 
    return (s.top());
}
