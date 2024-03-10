/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:31:31 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 18:07:39 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string		_type;
	
	public:
		WrongAnimal();
		WrongAnimal( const WrongAnimal &wrongAnimal);
		virtual ~WrongAnimal();
		std::string		getType() const;
		void			makeSound() const;

		WrongAnimal& operator=( const WrongAnimal &wrongAnimal );
};

#endif