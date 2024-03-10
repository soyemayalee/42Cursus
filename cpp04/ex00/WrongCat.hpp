/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:06:02 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 18:18:47 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

#include <iostream>

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat( const WrongCat &wrongCat );
		~WrongCat();

		void			makeSound() const;

		WrongCat& operator=( const WrongCat &wrongCat );
};

#endif