/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:32:40 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 18:02:58 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include <cstddef>

#include "Brain.hpp"

class Animal
{
	protected:
		std::string		_type;
	
	public:
		Animal();
		Animal( const Animal &animal);
		virtual ~Animal();
		std::string		getType() const;
		void			setType( std::string newType);
		virtual void	makeSound() const;

		Animal& operator=( const Animal &animal );
};

#endif