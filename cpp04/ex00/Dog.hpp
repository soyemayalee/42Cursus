/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:54:28 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 17:57:40 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog( const Dog &dog );
		~Dog();

		void			makeSound() const;

		Dog& operator=( const Dog &dog );
};

#endif