/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:31:21 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 18:18:23 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Animal (DOG) created through default constructor." << std::endl;
}

Dog::Dog( const Dog &dog ): Animal(dog)
{
	*this = dog;
	std::cout << "Animal (DOG) created through copy constructor." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Animal (DOG) desroyed through destructor." << std::endl;
}

Dog& Dog::operator=( const Dog &dog )
{
	_type = dog._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}