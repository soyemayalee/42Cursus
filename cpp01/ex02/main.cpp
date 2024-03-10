/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:46:36 by solee2            #+#    #+#             */
/*   Updated: 2023/12/21 17:17:15 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( void )
{
	std::string	sentence = "HI THIS IS BRAIN";
	std::string	*stringPTR = &sentence;
	std::string	&stringREF = sentence;

	//memory address
	std::cout << "Address (&sentence): " << &sentence << std::endl;
	std::cout << "Address (stringPTR): " << stringPTR << std::endl;
	std::cout << "Address (&stringREF) " << &stringREF << std::endl;

	//value
	std::cout << "Value (sentence): " << sentence << std::endl;
	std::cout << "Value (*stringPTR): " << *stringPTR << std::endl;
	std::cout << "Value (stringREF): " << stringREF << std::endl;
}


