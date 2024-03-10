/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:46:36 by solee2            #+#    #+#             */
/*   Updated: 2023/12/27 14:57:09 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	std::string	name;

	//stack
	std::cout << "Enter New Zombie's Name (stack)" << std::endl;
	std::cout << "Name: " << std::flush;
	std::cin >> name;

	Zombie	zombieOne(name);
	zombieOne.announce();

	//heap
	std::cout << "Enter New Zombie's Name (heap)" << std::endl;
	std::cout << "Name: " << std::flush;
	std::cin >> name;

	Zombie*	zombieTwo = newZombie(name);
	zombieTwo->announce();
	delete zombieTwo;

	std::cout << "Calling randomChump()" << std::endl;
	randomChump("Zommbbie");

	std::cout << "randomChump() called by user" << std::endl;
	std::cout << "Name (for randomChump): " << std::flush;
	std::cin >> name;
	randomChump(name);
	return (0);
}



/* 
Stack & Heap
1. Stack
	- memory of zombieOne is allocated automatically (when the program
	enters the scope)
	- object automatically deallocated when it goes out of scape
	(= when main function finishes execution)
2. Heap
	- created to heap using 'new' operator
	- newZombie function returns a pointer to the dynamically allocated
	Zombie object
	- the object remains in memory until explicitly deallocated using
	'delete' operator (=freeing memory allocation)
*/