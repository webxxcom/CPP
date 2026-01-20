/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkravche <rkravche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:36:51 by rkravche          #+#    #+#             */
/*   Updated: 2025/10/18 14:50:18 by rkravche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"
#include <iostream>

void Harl::debug(void)
{
    std::cout << "[DEBUG]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put "
    "enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]\n";
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl
        << "I’ve been coming for years, whereas you started working here just last month.\n"
        << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int idx;
    for(idx = 0;idx < 4; ++idx)
        if (levels[idx] == level)
            break;
    switch (idx)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
    }
}
