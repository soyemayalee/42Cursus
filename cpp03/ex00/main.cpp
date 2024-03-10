

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	robotOne("Random");

	std::cout << std::endl;
	std::cout << "-----------Game Start-----------" << std::endl;
	robotOne.attack("player 1");
	robotOne.attack("player 2");
	robotOne.attack("player 3");
	robotOne.attack("player 1");
	robotOne.attack("player 2");
	robotOne.takeDamage(8);
	robotOne.attack("player 1");
	robotOne.beRepaired(5);
	robotOne.beRepaired(5);
	robotOne.beRepaired(5);
	robotOne.takeDamage(18);
	robotOne.takeDamage(20);
	robotOne.beRepaired(5);
	robotOne.beRepaired(5);
	robotOne.attack("void");

	return (0);
}