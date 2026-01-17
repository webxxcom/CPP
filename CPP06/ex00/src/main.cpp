/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webxxcom <webxxcom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:51:10 by webxxcom          #+#    #+#             */
/*   Updated: 2026/01/17 16:50:59 by webxxcom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.h"

static void test(const std::string& input)
{
    std::cout << "==============================" << std::endl;
    std::cout << "Input: \"" << input << "\"" << std::endl;
    std::cout << "------------------------------" << std::endl;
    ScalarConverter::convert(input);
    std::cout << std::endl;
}

int main()
{
    /* CHAR TESTS */
    test("a");
    test("Z");
    test("0");
    test("!");

    /* INT TESTS */
    test("0");
    test("42");
    test("-42");
    test("127");
    test("128");        // char overflow
    test("2147483647"); // INT_MAX
    test("-2147483648");// INT_MIN

    /* FLOAT TESTS */
    test("0.0f");
    test("42.0f");
    test("-4.2f");
    test("4.2f");

    // /* DOUBLE TESTS */
    test("0.0");
    test("42.0");
    test("-4.2     ");
    test("4.2");
    test("-.5");

    /* PSEUDO-LITERALS (FLOAT) */
    test("nanf");
    test("+inff");
    test("-inff");

    /* PSEUDO-LITERALS (DOUBLE) */
    test("nan");
    test("+inf");
    test("-inf");
    
    /* INVALID INPUTS */
    test("hello");
    test("42ff");
    test("4.2.1");
    test("");
    test(" ");
    test("256");     // char impossible
    test("31");      // non-displayable char
    test("127.0f");
    test("1e10");

    return 0;
}
