/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webxxcom <webxxcom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:51:10 by webxxcom          #+#    #+#             */
/*   Updated: 2026/02/24 20:14:14 by webxxcom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

static const std::string DB_NAME = "./resources/data.csv";

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try {
        BitcoinExchange be(DB_NAME);
        be.calculate(argv[1]);
    }
    catch (std::exception const &ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
}
