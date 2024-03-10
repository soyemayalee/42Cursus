/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:14:16 by solee2            #+#    #+#             */
/*   Updated: 2023/12/28 19:51:32 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixedValue = 0;
	std::cout << "Default Constructor Called" << std::endl;
}

Fixed::Fixed( Fixed &copy)
{
	std::cout << "Copy Constructor Called" << std::endl;
	this->setRawBits(copy.getRawBits());
}

Fixed::~Fixed()
{
	std::cout << "Destrcutor Called" << std::endl;
}

Fixed& Fixed::operator=( Fixed &right )
{
	//definition for : this->_fixedValue = raw;
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &right)
		this->_fixedValue = right.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits Member Function Called" << std::endl;
	return this->_fixedValue;
}

void	Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits Member Function Called" << std::endl;
	this->_fixedValue = raw;
}
