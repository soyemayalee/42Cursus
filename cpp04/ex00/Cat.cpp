/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:31:19 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 18:18:18 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Animal (CAT) created through default constructor." << std::endl;
}
Cat::Cat( const Cat &cat)
{
	*this = cat;
	std::cout << "Animal (CAT) created through copy constructor." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Animal (CAT) destroyed through destructor." << std::endl;
}

Cat& Cat::operator=( const Cat &cat )
{
	_type = cat._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}