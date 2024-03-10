/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 03:23:17 by solee2            #+#    #+#             */
/*   Updated: 2023/12/27 15:27:48 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA(void)
{
}

void	HumanA::attack(void) const
{
	if (this->_weapon.getType() != "")
		std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	else
		std::cout << this->_name << " has no weapons." << std::endl;
}