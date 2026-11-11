#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <list>
#include <stdexcept>

// stack uses std::deque by default which i use in ex02
typedef std::stack<long long, std::list<long long> > Stack;

static bool isoperand(char ch)
{
    return (ch == '/' || ch == '*' || ch == '+' || ch == '-');
}

static void process_oper(Stack &s, char oper)
{
    long long n;
    long long res;

    if (s.size() < 2)
        throw std::runtime_error("Error: Excessive operand");
    n = s.top();
    s.pop();
    res = s.top();
    s.pop();

    switch (oper)
    {
    case '/':
        if (n == 0)
            throw std::runtime_error("Error: Division by zero");
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
RPN::RPN(RPN const &other) { *this = other; }
RPN &RPN::operator=(RPN const &other) { (void)other; return *this; }
RPN::~RPN() {}

long long RPN::calculate(std::string const &expr)
{
    Stack s;

    for (size_t i = 0; i < expr.size(); ++i)
    {
        if (std::isdigit(expr[i]))
        {
            // Numbers must be less than 10
            if (i + 1 < expr.size() && std::isdigit(expr[i + 1]))
                throw std::runtime_error("Error: Number must be less than 10");

            s.push(expr[i] - '0');
        }
        else if (isoperand(expr[i]))
            process_oper(s, expr[i]);
        else if (!std::isspace(expr[i]))
            throw std::runtime_error("Error: Unknown character occured");
    }
    if (s.size() != 1)
        throw std::runtime_error("Error: Not finished result");

    return (s.top());
}
