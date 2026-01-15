/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webxxcom <webxxcom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:22:25 by webxxcom          #+#    #+#             */
/*   Updated: 2026/01/15 22:09:20 by webxxcom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include <iostream>

void testInstantiate(std::string const &name, short grade)
{
    std::cout << "Creating bureaucrat with name=" << name << " and grade=" << grade << std::endl;
    try
    {
        Bureaucrat b1(name, grade);
        std::cout << "Success: " << b1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Failed: exception encountered: " << e.what() << std::endl;
    }
}

void testIncrement(std::string const &name, short grade, char mode)
{
    if (mode != 'i' && mode != 'd')
        return ;
        
    std::cout << "Creating bureaucrat with name=" << name << " and grade=" << grade << std::endl;
    try
    {
        Bureaucrat b1(name, grade);
        std::cout << "Created: " << b1 << std::endl;
        if (mode == 'i')
        {
            std::cout << "Now incrementing grade" << std::endl;
            b1.incrementGrade();
            std::cout << b1 << std::endl;
            b1.incrementGrade();
            std::cout << b1 << std::endl;
        }
        else if (mode == 'd')
        {
            std::cout << "Now decrementing grade" << std::endl;
            b1.decrementGrade();
            std::cout << b1 << std::endl;
            b1.decrementGrade();
            std::cout << b1 << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Failed: exception encountered: " << e.what() << std::endl;
    }
}

int main()
{
    testInstantiate("B1", 123);
    std::cout << "\n";
    testInstantiate("B2", 151);
    std::cout << "\n";
    testInstantiate("B3", -12);
    std::cout << "\n";
    testIncrement("B4", 12, 'i');
    std::cout << "\n";
    testIncrement("B5", 2, 'i');
    std::cout << "\n";
    testIncrement("B6", 2, 'd');
    std::cout << "\n";
    testIncrement("B6", 149, 'd');
}