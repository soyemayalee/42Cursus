/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:54:54 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 17:57:44 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat( const Cat &cat );
		~Cat();

		void			makeSound() const;

		Cat& operator=( const Cat &cat );
};

#endif