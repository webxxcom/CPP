/* --- ScalarConverter.cpp --- */

/* ------------------------------------------
author: Webxxcom
date: 1/17/2026
------------------------------------------ */

#include "ScalarConverter.h"
#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <limits>
#include <string>
#include <sstream>
#include <cmath>

/**
 * Properly convert:
 *      chars: convert("A") or convert("2")
 *      pseudo-literals: convert("nanf") or convert("+inf")
 *      numbers: convert("42") or convert(12312.4124)
 * Invalid:
 *      words: convert("hello") or convert (h2);
 *      invalid format: convert(3.2.2) or convert(123.ff)
 */
void ScalarConverter::convert(std::string literal)
{
    double value;

    if (isPseudoVal(literal))
    {
        value = ((literal[0] == '-') ? -INFINITY :
            ((literal[0] == '+') ? INFINITY : NAN));
    }
    if (isChar(literal))
    {
        value = static_cast<double>(literal[0]);
    }
    if (isInt(literal))
        value = static_cast<double>(std::atoi(literal.c_str()));
    else if (isFloat(literal) || isDouble(literal))
    {
        value = std::strtod(literal.c_str(), NULL);
    }
    else
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

ScalarConverter::ScalarConverter() { }
ScalarConverter::~ScalarConverter() { }

bool ScalarConverter::isPseudoVal(std::string str)
{
    return (str == "nan" || str == "+inff" || str == "-inff" || str == "+inf" || str == "-inf");
}

bool ScalarConverter::isChar(std::string str)
{
    return str.size() == 1 && !isdigit(str[0]);
}

bool ScalarConverter::isInt(std::string str)
{
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+')
        ++i;
    if (i == str.size())
        return (false);
    for(; i < str.size(); ++i)
        if (!isdigit(str[i]))
            return false;
    return true;
}

bool ScalarConverter::isFloat(std::string str)
{
    if (str.size() == 0 || str[str.size() - 1] != 'f')
        return (false);
    char *end;
    std::strtod(str.c_str(), &end);
    return (*end == 'f');
}

bool ScalarConverter::isDouble(std::string str)
{
    char *end;
    std::strtod(str.c_str(), &end);
    return (end != NULL);
}

void ScalarConverter::printChar(double val)
{
    std::cout << "char: ";
    if (std::isnan(val) || val > std::numeric_limits<char>::max() || val < std::numeric_limits<char>::min())
        std::cout << "impossible";
    else if (std::isprint(static_cast<int>(val)))
        std::cout << '\''<< static_cast<char>(val) << '\'';
    else
        std::cout << "Non displayable";
    std::cout << '\n';
}

void ScalarConverter::printInt(double val)
{
    if (std::isnan(val) || val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(val) << '\n';
}

void ScalarConverter::printFloat(double val)
{
    float f = static_cast<float>(val);
    std::cout << "float: " << f;
    if (std::abs(f - (int)f) < 0.00001f)
        std::cout << ".0";
    std::cout << "f\n";
}

void ScalarConverter::printDouble(double val)
{
    std::cout << "double: " << val;
    if (std::abs(val - (int)val) <0.00001)
        std::cout << ".0";
    std::cout << '\n';
}
