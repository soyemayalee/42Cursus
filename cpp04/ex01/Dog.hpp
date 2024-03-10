
#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
#include <cstddef>

#include "Animal.hpp"

class Dog: public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog();
		Dog( const Dog &dog );
		~Dog();

		void			makeSound() const;

		Dog& operator=( const Dog &dog );
};

#endif