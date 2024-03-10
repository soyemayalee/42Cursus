/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:10:38 by solee2            #+#    #+#             */
/*   Updated: 2023/12/28 19:08:13 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <climits>

class	Fixed
{
	private:
		int					_fixedValue;
		static const int	_fractionBits = 8;
	public:
		Fixed( void );
		Fixed( const Fixed &copy);
		Fixed( const int input);
		Fixed( const float input);
		~Fixed();

		Fixed&	operator=( const Fixed &rhs );

		int		getRawBits( void ) const;
		void	setRawBits( int raw );
		float	toFloat ( void ) const;
		int		toInt ( void ) const;
		
};

std::ostream& operator<<( std::ostream &o, Fixed const &i);

#endif