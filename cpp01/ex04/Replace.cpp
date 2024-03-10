/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:12:08 by solee2            #+#    #+#             */
/*   Updated: 2023/12/27 15:55:06 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string file) : _inFile(file)
{
	this->_outFile = this->_inFile + ".replace";
}

Replace::~Replace(void)
{
}

int	Replace::replace(std::string str1, std::string str2)
{
	if (str1.empty() || str2.empty())
	{
		std::cout << "Empty String(s)" << std::endl;
		return (1);
	}
	std::ifstream ifs(this->_inFile);
	if (!ifs.is_open())
	{
		std::cerr << "Error Opening File (" << this->_inFile << ")" << std::endl;
		return (1);
	}
	else
	{
		std::string	line;
	
		if (std::getline(ifs, line, '\0'))
		{
			std::ofstream ofs(this->_outFile);
			size_t	index = line.find(str1);
			while (index < std::string::npos)
			{
				line.erase(index, str1.length());
				line.insert(index, str2);
				index = line.find(str1);
			}
			ofs << line; // outputting data to the file (write line to outfile)
			ofs.close();
		}
		else
			std::cout << "Error: Empty File" << std::endl;
		ifs.close();
	}
	return (0);
}


/* std::string::npos */
/*
	- special constant value defined in C++ standard library
	- representes the max possible value for size_t type
	- in context of string searching npos is used to indicate
	that a search operation did not find the target substring
	within the string (when find() doesn't find a substring, it
	would return npos)
*/