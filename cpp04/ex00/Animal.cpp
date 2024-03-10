/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:31:10 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 15:31:43 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "Human";
	std::cout << "Animal created through default constructor." << std::endl;
}

Animal::Animal( const Animal &animal)
{
	*this = animal;
	std::cout << "Animal created through copy constructor." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal has been destroyed by destructor." << std::endl;
}

Animal& Animal::operator=( const Animal &animal )
{
	_type = animal._type;
	//std::cout << "Animal (" << this->_type << ") copy assignment called." << std::endl;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Hooomaaaan" << std::endl;
}

std::string Animal::getType( void ) const
{
	return (this->_type);
}