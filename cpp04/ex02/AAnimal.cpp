/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:33:49 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 16:41:03 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->_type = "Human";
}

AAnimal::AAnimal( const AAnimal &animal)
{
	*this = animal;
}

AAnimal::~AAnimal()
{

}

AAnimal& AAnimal::operator=( const AAnimal &animal )
{
	_type = animal._type;
	return (*this);
}

void	AAnimal::makeSound() const
{
	std::cout << "Hooomaaaan" << std::endl;
}

void	AAnimal::setType( std::string newType )
{
	this->_type = newType;
}

std::string AAnimal::getType( void ) const
{
	return (this->_type);
}