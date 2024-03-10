/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:31:35 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 18:18:53 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "Cat";
	std::cout << "WrongAnimal (WRONGCAT) created through default constructor." << std::endl;
}

WrongCat::WrongCat( const WrongCat &wrongCat)
{
	*this = wrongCat;
	std::cout << "WrongAnimal (WRONGCAT) created through copy constructor." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongAnimal (WRONGCAT) destroyed through desructor." << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat &wrongCat )
{
	_type = wrongCat._type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "bibidi babidi boo" << std::endl;
}