/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:33:02 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 18:23:24 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "Unicorn";
	std::cout << "WrongAnimal created through default constructor." << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &wrongAnimal)
{
	*this = wrongAnimal;
	std::cout << "WrongAnimal created through copy constructor." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed through destructor." << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal &wrongAnimal )
{
	_type = wrongAnimal._type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "wee hee--" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return (this->_type);
}