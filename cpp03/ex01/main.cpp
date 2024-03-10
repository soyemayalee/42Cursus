

#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap	robotClap("robotC");
	ScavTrap	robotScav("robotS");
	ScavTrap	robotScavCopy(robotScav);

	robotClap.attack("robotOne");
	robotScav.attack("robotTwo");
	robotClap.takeDamage(20);
	robotClap.takeDamage(20);
	robotScavCopy.attack("robotThree");
	robotClap.beRepaired(20);
	robotScav.attack("robotThree");
	robotScav.takeDamage(40);
	robotScavCopy.takeDamage(12);
	robotScavCopy.beRepaired(20);
	robotScav.beRepaired(30);
	robotScav.guardGate();
	robotScav.beRepaired(240);

	return (0);
}