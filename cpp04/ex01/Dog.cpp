/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:32:55 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 20:27:17 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Animal (DOG) created through default constructor." << std::endl;
	this->_brain = new Brain();
}

Dog::Dog( const Dog &dog ): Animal(dog)
{
	std::cout << "Animal (DOG) created through copy constructor." << std::endl;
	this->_brain = new Brain(*(dog._brain));
	*this = dog;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Animal (DOG) destroyed through destructor." << std::endl;
}

Dog& Dog::operator=( const Dog &dog )
{
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*(dog._brain));
	this->_type = dog._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}