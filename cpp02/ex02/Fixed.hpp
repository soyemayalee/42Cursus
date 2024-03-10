/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:10:38 by solee2            #+#    #+#             */
/*   Updated: 2023/12/28 19:46:06 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class	Fixed
{
	private:
		int					_fixedValue;
		static const int	_fractionBits = 8;

	public:
		Fixed( void );
		Fixed( const Fixed& copy);
		Fixed( const int input);
		Fixed( const float input);
		~Fixed();

		Fixed& operator=( const Fixed& right);

		bool operator<( const Fixed& input ) const;
		bool operator>( const Fixed& input ) const;
		bool operator<=( const Fixed& input ) const;
		bool operator>=( const Fixed& input ) const;
		bool operator==( const Fixed& input ) const;
		bool operator!=( const Fixed& input ) const;

		Fixed operator+( const Fixed& input ) const;
		Fixed operator-( const Fixed& input ) const;
		Fixed operator*( const Fixed& input ) const;
		Fixed operator/( const Fixed& input ) const;

		Fixed& operator++();
		Fixed& operator--();

		Fixed operator++( int );
		Fixed operator--( int );

		static Fixed& min(Fixed& left, Fixed& right);
		static Fixed& max(Fixed& left, Fixed& right);
		static const Fixed& min(const Fixed& left, const Fixed& right);
		static const Fixed& max(const Fixed& left, const Fixed& right);
		

		int	getRawBits( void ) const;
		void	setRawBits( const int raw );
		float	toFloat ( void ) const;
		int		toInt ( void ) const;
		
};

std::ostream& operator<<( std::ostream &o, Fixed const &i);

#endif