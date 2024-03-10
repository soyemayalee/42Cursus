/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:34:03 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 18:24:34 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

#include <iostream>
#include <string>
#include <cstddef>

#include "Brain.hpp"

class AAnimal
{
	protected:
		std::string		_type;
	
	public:
		AAnimal();
		AAnimal( const AAnimal &animal);
		virtual ~AAnimal();
		std::string		getType() const;
		void			setType( std::string newType);
		virtual void	makeSound() const = 0;

		AAnimal& operator=( const AAnimal &animal );
};

#endif