/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:37:18 by solee2            #+#    #+#             */
/*   Updated: 2023/12/27 16:14:10 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << std::endl;
	std::cout << BLUE
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
	<<NO_COLOUR << std::endl;
}

void	Harl::info(void)
{
	std::cout << std::endl;
	std::cout << BLUE
	<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
	<<NO_COLOUR << std::endl;
}

void	Harl::warning(void)
{
	std::cout << std::endl;
	std::cout << BLUE
	<< "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
	<<NO_COLOUR << std::endl;
}

void	Harl::error(void)
{
	std::cout << std::endl;
	std::cout << BLUE
	<< "This is unacceptable! I want to speak to the manager now."
	<<NO_COLOUR << std::endl;
}

void	Harl::complain(std::string level)
{
	t_func	functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i == 3 && levels[i].compare(level) != 0)
		{
			if (level.compare("exit") != 0)
			{
				std::cout << RED << "No Such Command: Check Again" << NO_COLOUR << std::endl;
				/* i = i + 2; */
			}
		}
		else if (levels[i].compare(level) == 0)
		{
			(this->*functions[i])();
			i = 5;
		}
		i++;
	}
}