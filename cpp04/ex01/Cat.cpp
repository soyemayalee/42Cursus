/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:32:52 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 20:28:07 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Animal (CAT) created through default constructor." << std::endl;
	this->_brain = new Brain();
}
Cat::Cat( const Cat &cat): Animal(cat)
{
	/* *this = cat; */
	/*
		==> this is incorrect. this will create Animal first, go to = operator
		where it will check if _brain exists, making conditional jump (as the
		brain is not created yet)
	*/
	std::cout << "Animal (CAT) created through default constructor." << std::endl;
	this->_brain = new Brain(*(cat._brain));
	*this = cat;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Animal (CAT) destroyed through destructor." << std::endl;
}

Cat& Cat::operator=( const Cat &cat )
{
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain(*(cat._brain));
	this->_type = cat._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
