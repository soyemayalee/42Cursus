/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:32:47 by solee2            #+#    #+#             */
/*   Updated: 2023/12/30 16:50:06 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>
#include <cstddef>

class Brain
{
	private:
		std::string		_ideas[100];
	
	public:
		Brain();
		Brain( const Brain &brain );
		~Brain();
	
		Brain& operator=( const Brain &brain );
};

#endif