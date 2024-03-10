/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 01:00:12 by solee2            #+#    #+#             */
/*   Updated: 2023/12/27 14:32:10 by solee2           ###   ########.fr       */
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
		Zombie( std::string name ); //constructor
		~Zombie(); //destructor
		void	announce( void ); //member function
		Zombie*	newZombie( std::string name ); //global function
		void	randomChump( std::string name ); //global function
};

Zombie*	newZombie( std::string name ); //global function
void	randomChump( std::string name ); //global function

#endif