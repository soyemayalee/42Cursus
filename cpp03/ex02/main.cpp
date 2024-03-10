

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	FragTrap	robotFrag("robotF");
	ScavTrap	robotScav("robotS");
	FragTrap	robotFragCopy(robotFrag);


	robotFrag.attack("robotOne");
	robotScav.takeDamage(30);
	robotScav.attack("robotTwo");
	robotFragCopy.attack("robotOne");
	robotFrag.takeDamage(20);
	robotFrag.attack("robotOne");
	robotScav.takeDamage(30);
	robotFragCopy.attack("robotTwo");
	robotScav.attack("robotTwo");
	robotFrag.takeDamage(20);
	robotFrag.attack("robotOne");
	robotScav.takeDamage(30);
	robotScav.attack("robotTwo");
	robotFragCopy.takeDamage(12);
	robotFrag.takeDamage(20);
	robotScav.guardGate();
	robotScav.beRepaired(240);
	robotFragCopy.beRepaired(60);
	robotFrag.highFivesGuys();
	robotScav.attack("robotTwo");
	robotFrag.takeDamage(20);
	robotScav.attack("robotTwo");
	robotFrag.takeDamage(20);
	robotScav.attack("robotTwo");
	robotFrag.takeDamage(20);

	return (0);
}