/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:46:36 by solee2            #+#    #+#             */
/*   Updated: 2023/12/27 15:10:10 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define zombieNum 5

int	main( void )
{
	Zombie	*group = zombieHorde(zombieNum, "zoombieee");

	int	i;

	i = 0;
	std::cout << "Starting Zombie Horde Creation..." << std::endl;
	while (i < zombieNum)
	{
		group[i].announce();
		i++;
	}

	delete [] group;
	return (0);
}


