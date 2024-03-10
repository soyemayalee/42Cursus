/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:31:15 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 17:57:29 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string		_type;
	
	public:
		Animal();
		Animal( const Animal &animal);
		virtual ~Animal();
		std::string		getType() const;
		virtual void	makeSound() const;

		Animal& operator=( const Animal &animal );
};

#endif