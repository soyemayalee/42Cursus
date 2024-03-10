/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 00:37:22 by solee2            #+#    #+#             */
/*   Updated: 2023/12/27 16:11:14 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

#define BLUE		"\033[0;34m"
#define	RED			"\033[1;31m"
#define NO_COLOUR	"\033[0m"

class	Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl(void);
		~Harl();

		void	complain(std::string level);
};

typedef void (Harl::*t_func) ( void );

#endif