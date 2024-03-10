/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:14:16 by solee2            #+#    #+#             */
/*   Updated: 2023/12/29 21:44:20 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/* constructors & destructors */
Fixed::Fixed( void )
{
	this->_fixedValue = 0;
	/* std::cout << "Default Constructor Called" << std::endl; */
}

Fixed::Fixed( const Fixed &copy )
{
	*this = copy;
	/* std::cout << "Copy Constructor Called" << std::endl; */
}

Fixed::Fixed( const int input)
{
	this->_fixedValue = input << this->_fractionBits;
	/* std::cout << "Int Constructor Called" << std::endl; */
}

Fixed::Fixed( const float input)
{
	this->_fixedValue = std::roundf(input * (1 << this->_fractionBits));
	/* std::cout << "Float Constructor Called" << std::endl; */
}

Fixed::~Fixed()
{
	/* std::cout << "Destrcutor Called" << std::endl; */
}

/* operators */
Fixed& Fixed::operator=( const Fixed& right )
{
	//definition for : this->_fixedValue = raw;
	/* std::cout << "Copy Assignment Operator Called" << std::endl; */
	if (this != &right)
		this->_fixedValue = right.getRawBits();
	return *this;
}

bool Fixed::operator>( const Fixed& input ) const
{
	return (this->_fixedValue > input._fixedValue);
}

bool Fixed::operator<( const Fixed& input ) const
{
	return (this->_fixedValue < input._fixedValue);
}

bool Fixed::operator>=( const Fixed& input) const
{
	return (this->_fixedValue >= input._fixedValue);
}

bool Fixed::operator<=( const Fixed& input) const
{
	return (this->_fixedValue <= input._fixedValue);
}

bool Fixed::operator==( const Fixed& input) const
{
	return (this->_fixedValue == input._fixedValue);
}

bool Fixed::operator!=( const Fixed& input ) const
{
	return (this->_fixedValue != input._fixedValue);
}

Fixed Fixed::operator+( const Fixed& input) const
{
	Fixed	result;

	result._fixedValue = (this->_fixedValue + input._fixedValue);
	return (result);
}

Fixed Fixed::operator-( const Fixed& input) const
{
	Fixed	result;

	result._fixedValue = (this->_fixedValue - input._fixedValue);
	return (result);
}

Fixed Fixed::operator*( const Fixed& input) const
{
	Fixed	result(this->toFloat() * input.toFloat());

	return (result);
}

Fixed Fixed::operator/( const Fixed& input) const
{
	Fixed	result;

	result._fixedValue = (this->toFloat() / input.toFloat());
	return (result);
}

/* increments & decrements */
Fixed& Fixed::operator++( void )
{
	//pre-increment
		//increment first, use later
	this->_fixedValue++;
	return (*this);
}

Fixed& Fixed::operator--( void )
{
	//pre-decrement
		//decrement first, use later
	this->_fixedValue--;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	//post-increment
		//value incremented, but original (unmodified) value is used
		//in current expression
	Fixed	previous(*this); //copy of current object stored

	this->_fixedValue++;
	return (previous);
}

Fixed Fixed::operator--( int )
{
	//post-decrement
		//value decremented, but original (unmodified) value is used
		//in current expression
	Fixed	previous(*this);

	this->_fixedValue--;
	return (previous);
}

/* minimum & maximum */
Fixed&	Fixed::min( Fixed& left, Fixed& right )
{
	if (right >= left)
		return (left);
	return (right);
}

Fixed&	Fixed::max( Fixed& left, Fixed& right )
{
	if (right <= left)
		return (left);
	return (right);
}

const Fixed&	Fixed::min( const Fixed& left, const Fixed& right)
{
	if (right >= left)
		return (left);
	return (right);
}

const Fixed&	Fixed::max( const Fixed& left, const Fixed& right )
{
	if (right <= left)
		return (left);
	return (right);
}

/* setter & getter */

void	Fixed::setRawBits( int raw )
{
	this->_fixedValue = raw;
}

int	Fixed::getRawBits( void ) const
{
	/* std::cout << "getRawBits Function Called" << std::endl; */
	return this->_fixedValue;
}

/* util functions */

float	Fixed::toFloat ( void ) const 
{
	return static_cast<float>( this->_fixedValue ) / ( 1 << _fractionBits );
}

int		Fixed::toInt ( void ) const {
	return this->_fixedValue >> _fractionBits;
}

std::ostream& operator<<( std::ostream &o, Fixed const &i)
{
	o << i.toFloat(); //writing to ostream
	return o;
}