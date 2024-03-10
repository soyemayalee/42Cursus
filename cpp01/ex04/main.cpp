/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:46:36 by solee2            #+#    #+#             */
/*   Updated: 2023/12/07 00:21:45 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Wrong Number of Arguments" << std::endl;
		return (1);
	}

	Replace	replace(argv[1]);
	if (replace.replace(argv[2], argv[3]) != 0)
		return (1);
	return (0);
}


