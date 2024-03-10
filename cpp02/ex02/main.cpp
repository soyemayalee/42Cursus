/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:07:02 by solee2            #+#    #+#             */
/*   Updated: 2023/12/28 20:14:53 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );

	const Fixed c;
	const Fixed d( Fixed( 5.05f ) * Fixed( 2 ) );

	Fixed numA(-0.14f);
	Fixed numB(-0.14f);	
	
	//Fixed Point Number 1 (with format 8) ==> floating point number 0.00390625
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << " max(a,b):" << Fixed::max( a, b ) << std::endl;
	std::cout << " min(a,b):"<< Fixed::min( a, b ) << std::endl;

	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << " max(c, d):" << Fixed::max( c, d ) << std::endl;
	std::cout << " min(c, d):" << Fixed::min( c, d ) << std::endl;

	//std::cout << std::endl;	
	std::cout << "numA:" << numA;
	std::cout << " numB:" << numB << std::endl;	
	if (numA < numB)
		std::cout << "numA < numB is true\n";
	else
		std::cout << "numA < numB is false\n";
	if (numA <= numB)
		std::cout << "numA <= numB is true\n";
	else
		std::cout << "numA <= numB is false\n";
	if (numA > numB)
		std::cout << "numA > numB is true\n";
	else
		std::cout << "numA > numB is false\n";
	if (numA >= numB)
		std::cout << "numA >= numB is true\n";
	else
		std::cout << "numA >= numB is false\n";
	if (numA == numB)
		std::cout << "numA == numB is true\n";
	else
		std::cout << "numA == numB is false\n";
	if (numA != numB)
		std::cout << "numA != numB is true\n";
	else
		std::cout << "numA != numB is false\n";
	std::cout << std::endl;	
	std::cout << "numA + numB is " << numA + numB << std::endl; 
	std::cout << "numA - numB is " << numA - numB << std::endl;
	std::cout << "numA * numB is " << numA * numB << std::endl;
	std::cout << "numA / numB is " << numA / numB << std::endl;
	std::cout << std::endl;	
	
	return (0);
}