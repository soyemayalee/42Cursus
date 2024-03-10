/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:32:43 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 16:49:54 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\tBrain created through default constructor." << std::endl;
}

Brain::Brain( const Brain &brain )
{
	*this = brain;
	std::cout << "\tBrain created through copy constructor." << std::endl;
}

Brain::~Brain()
{
	std::cout << "\tBrain destroyed through destructor." << std::endl;
}

Brain&	Brain::operator=( const Brain &brain )
{
	for (size_t i = 0; i < 100; i++)
	{
		this->_ideas[i] = brain._ideas[i];
	}
	return (*this);
}

