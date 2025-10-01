/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: webxxcom <webxxcom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 10:36:46 by webxxcom          #+#    #+#             */
/*   Updated: 2025/10/01 09:45:54 by webxxcom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; ++i)
			for (size_t j = 0; argv[i][j]; ++j)
				std::cout << (char)std::toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}