/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:46:36 by solee2            #+#    #+#             */
/*   Updated: 2023/12/27 16:53:14 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	std::string	input;
	Harl	Harl;

	do {
		std::cout << "-------------------------------" << std::endl;
		std::cout << "------------OPTIONS------------" << std::endl;
		std::cout << "DEBUG" << std::endl;
		std::cout << "INFO" << std::endl;
		std::cout << "WARNING" << std::endl;
		std::cout << "ERROR" << std::endl;
		std::cout << std::endl;
		std::cout << "++Make Sure There Are No Typos++" <<std::endl;
		std::cout << "Type \"exit\" to end program" << std::endl;
		std::cout << "-------------------------------" << std::endl;
		std::cout << "Complain Level: ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "STOP" << std::endl;
			break ;
		}
		//std::cin >> input;
		if (input != "")
			Harl.complain(input);
		std::cout << std::endl;
	} while (input.compare("exit") != 0);
	return (0);
}


