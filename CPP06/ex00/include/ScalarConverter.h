/* --- ScalarConverter.h --- */

/* ------------------------------------------
Author: Webxxcom
Date: 1/17/2026
------------------------------------------ */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <sstream>

class ScalarConverter {
public:

    static void convert(std::string literal);
private:
    ScalarConverter();
    ~ScalarConverter();

    static bool isPseudoVal(std::string str);
    static bool isChar(std::string str);
    static bool isInt(std::string str);
    static bool isDouble(std::string str);
    static bool isFloat(std::string str);

    static void printChar(double val);
    static void printInt(double val);
    static void printFloat(double val);
    static void printDouble(double val);
};

#endif // SCALARCONVERTER_H
