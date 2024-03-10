/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 01:00:12 by solee2            #+#    #+#             */
/*   Updated: 2023/12/21 17:06:10 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string _name;
	
	public:
		Zombie(); //constructor
		~Zombie(); //destructor
		void	announce( void ); //member function
		Zombie	*newZombie( std::string name ); //global function
		void	setName( std::string name );
};

Zombie	*zombieHorde( int N, std::string name );

#endif