/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:32:34 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 16:27:56 by solee2           ###   ########.fr       */
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
	std::cout << "Animal destroyed through destructor." << std::endl;
}

Animal& Animal::operator=( const Animal &animal )
{
	_type = animal._type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Hooomaaaan" << std::endl;
}

void	Animal::setType( std::string newType )
{
	this->_type = newType;
}

std::string Animal::getType( void ) const
{
	return (this->_type);
}