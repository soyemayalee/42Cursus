/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:10:38 by solee2            #+#    #+#             */
/*   Updated: 2023/12/28 19:51:37 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					_fixedValue;
		static const int	_fractionBits = 8;

	public:
		Fixed();
		Fixed( Fixed &copy);
		Fixed& operator=( Fixed &right );
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

};

#endif