
#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
#include <cstddef>

#include "Animal.hpp"

class Cat: public Animal
{
	private:
		Brain	*_brain;

	public:
		Cat();
		Cat( const Cat &cat );
		~Cat();

		void			makeSound() const;

		Cat& operator=( const Cat &cat );
};

#endif