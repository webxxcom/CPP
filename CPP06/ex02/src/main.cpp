/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webxxcom <webxxcom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:33:12 by webxxcom          #+#    #+#             */
/*   Updated: 2026/01/17 18:51:10 by webxxcom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.h"
#include "B.h"
#include "C.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

static Base * generate(void)
{
    int val = rand() % 3;
    if (val == 0)
        return new A();
    else if (val == 1)
        return new B();
    else
        return new C();
}

static void identify(Base* p)
{
    A* a = dynamic_cast<A *>(p);
    if (a)
    {
        std::cout << "Param is of type A\n";
        return ;
    }
    B* b = dynamic_cast<B *>(p);
    if (b)
    {
        std::cout << "Param is of type B\n";
        return ;
    }
    C* c = dynamic_cast<C *>(p);
    if (c)
    {
        std::cout << "Param is of type C\n";
        return ;
    }
}

void identify(Base& p)
{
    // identify(&p);
    try
    {
        A &a = dynamic_cast<A &>(p);
        std::cout << "Param is of type A\n";
        return ;
    }
    catch(const std::exception& e)
    { }
    try
    {
        B &b = dynamic_cast<B &>(p);
        std::cout << "Param is of type B\n";
        return ;
    }
    catch(const std::exception& e)
    { }
    try
    {
        C &c = dynamic_cast<C &>(p);
        std::cout << "Param is of type C\n";
        return ;
    }
    catch(const std::exception& e)
    { }
}

int main()
{
    srand((time_t)time(NULL));

    Base *obj = generate();
    identify(obj);
    identify(*obj);
    delete obj;
}