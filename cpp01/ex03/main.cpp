/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:46:36 by solee2            #+#    #+#             */
/*   Updated: 2023/12/27 16:43:29 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	std::string	newType;
	Weapon weaponOne = Weapon("machete");
	HumanA Nick("Nick", weaponOne);
	Nick.attack();
	std::cout << "Set/Change Weapons: " << std::flush;
	std::getline(std::cin, newType);
	//std::cin >> newType;
	weaponOne.setType(newType);
	Nick.attack();

	Weapon weaponTwo = Weapon("machete");
	HumanB Judy("Judy");
	//Judy.setWeapon(weaponTwo);
	Judy.attack();
	Judy.setWeapon(weaponTwo);
	std::cout << "Set/Change Weapons: " << std::flush;
	std::getline(std::cin, newType);
	//std::cin >> newType;
	weaponTwo.setType(newType);
	Judy.attack();
	return (0);
}

