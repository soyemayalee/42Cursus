/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:14:16 by solee2            #+#    #+#             */
/*   Updated: 2023/12/28 19:56:45 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->_fixedValue = 0;
	std::cout << "Default Constructor Called" << std::endl;
}

Fixed::Fixed( const Fixed &copy )
{
	*this = copy;
	std::cout << "Copy Constructor Called" << std::endl;
}

Fixed::Fixed( const int input)
{
	this->_fixedValue = input << this->_fractionBits;
	std::cout << "Int Constructor Called" << std::endl;
}

Fixed::Fixed( const float input)
{
	this->_fixedValue = std::roundf(input * (1 << this->_fractionBits));
	/* explanation*/
	/*
		input * (1 << _fractionBits)

		=scales the input value by multiplying it by the 'scaling factor'
		"(1 << _fractionBits)"
		=crucial in coverting floating point value to fixed point value
		while preservng the correct fractional precision

		roundf: the result of multiplication is rounded to the
		nearest integer ==> ensure the fixed point value is correctly
		rounded to the nearest integer value based on the fractional part
	*/
	std::cout << "Float Constructor Called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destrcutor Called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed &right )
{
	//definition for : this->_fixedValue = raw;
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &right)
		this->_fixedValue = right.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	return this->_fixedValue;
}

void	Fixed::setRawBits( int raw )
{
	this->_fixedValue = raw;
}


float	Fixed::toFloat ( void ) const 
{

	return static_cast<float>( this->getRawBits() ) / ( 1 << this->_fractionBits );
}

int		Fixed::toInt ( void ) const {
	return this->_fixedValue >> this->_fractionBits;
}

std::ostream& operator<<( std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}