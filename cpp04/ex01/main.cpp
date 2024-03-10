/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:32:58 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 20:26:20 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	Animal	*animalArr[20];

	for (size_t i = 0; i < 20; i++)
	{
		std::cout << std::endl;
		if (i % 2 == 0)
			animalArr[i] = new Dog(); //create dog
		else
			animalArr[i] = new Cat(); //create cat
	}

	std::cout << "----------------------------------------------------" << std::endl;

	std::cout << "-------------------Deep Copy Check-------------------" << std::endl;
	
	Cat	newCat = *(static_cast<Cat *>(animalArr[3]));
	animalArr[3]->setType("Wildcat");
	std::cout << "cat 3: " << animalArr[3]->getType() << std::endl;
	std::cout << "newcat: " << newCat.getType() << std::endl;

	std::cout << "----------------------------------------------------" << std::endl;

	for (size_t j = 0; j < 20; j++)
	{
		delete animalArr[j];
		/* explanation */
		/*
			we created an array of Animal. So, we can't access
			the 'brain' variables. So when the parent class's 
			destructor is called, the derived class's desturctor
			is not called, potentially creating a leak.

			if we define the destructor as virtual 
			(i.e. virtual ~Animal()), this directs the destructor
			call to the most derived class's destructor 
		*/
	}
	return (0);
}
