/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:15:09 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 18:26:48 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	/* AAnimal aAnimal; */
	/*
		because it's an abstract class, 
		the variable cannot be declared
	*/

	//Dog jCopy = *static_cast<const Dog *>(j);

	AAnimal	*animals[4];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	animals[0]->makeSound();
	animals[1]->makeSound();
	animals[2]->makeSound();
	animals[3]->makeSound();

	std::cout << "----------------------------------------------------" << std::endl;

	std::cout << "-------------------Deep Copy Check-------------------" << std::endl;
	animals[1]->setType("Wildcat");
	std::cout << "cat 3: " << animals[1]->getType() << std::endl;
	std::cout << "cat 19: " << animals[3]->getType() << std::endl;

	std::cout << "----------------------------------------------------" << std::endl;

	delete animals[0];
	delete animals[1];
	delete animals[2];
	delete animals[3];

	return (0);
}

