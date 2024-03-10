/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:15:17 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 18:26:54 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include <cstddef>

#include "AAnimal.hpp"
#include "Animal.hpp"

class Cat: public AAnimal
{
	private:
		Brain	*_brain;

	public:
		Cat();
		Cat( const Cat &cat );
		~Cat();

		void			makeSound() const;

		Cat& operator=( const Cat &cat );
};

#endif