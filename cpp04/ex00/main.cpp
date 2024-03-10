/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:31:24 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 18:19:41 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Dog jCopy = *static_cast<const Dog *>(j);

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << jCopy.getType() << " " << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();
	jCopy.makeSound();

	std::cout << "------------------" << std::endl;
	const WrongAnimal* beta = new WrongAnimal();
	const WrongAnimal* kittie = new WrongCat();
	std::cout << beta->getType() << " " << std::endl;
	std::cout << kittie->getType() << " " << std::endl;
	beta->makeSound();
	kittie->makeSound();

	delete meta;
	delete i;
	delete j;
	delete beta;
	delete kittie;

	return (0);
}

	/* no need to delete jCopy */
	/*
		- if created to stack, no need to delete
		+ stack vs heap 
			- if we use 'new' with pointer, it goes to heap
			- if not, it goes to stack

			- if it goes to stack, it automatically deletes through destructor
	*/