#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class	ClapTrap
{
	private:
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;

	public:
		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &input );
		~ClapTrap();

		ClapTrap& operator=( const ClapTrap& input );

		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

};

#endif