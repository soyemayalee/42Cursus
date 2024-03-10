/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:32:02 by solee2            #+#    #+#             */
/*   Updated: 2023/12/07 00:19:37 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>

class	Replace
{
	private:
		std::string	_inFile;
		std::string	_outFile;

	public:
		Replace(std::string file);
		~Replace();
		int	replace(std::string str1, std::string str2);
};

#endif