/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:28:27 by solee2            #+#    #+#             */
/*   Updated: 2023/12/27 15:06:53 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie	*zombieGroup = new Zombie[N];
	int	count;

	count = 0;
	while (count < N)
	{
		zombieGroup[count].setName(name);
		count++;
	}
	return (zombieGroup);
}