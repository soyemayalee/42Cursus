
#include "ScavTrap.hpp"

/* constructors & destructors */
ScavTrap::ScavTrap( void ): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " has been created through scavtrap default constructor" << std::endl;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " has been created through scavtrap name-given constructor" << std::endl;
}


ScavTrap::ScavTrap( const ScavTrap &input ): ClapTrap(input)
{
	std::cout << "ScavTrap " << this->_name << " has been created through scavtrap copy constructor" << std::endl;

}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " has been destroyed through scavtrap destructor" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& input )
{
	this->_name = input._name;
	this->_hitPoints = input._hitPoints;
	this->_energyPoints = input._energyPoints;
	this->_attackDamage = input._attackDamage;
	return (*this);
}

/* functions */

void	ScavTrap::attack( const std::string& target )
{
	if (this->_hitPoints == 0)
		std::cout << this->_name << "is dead. No attack possible." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << "has no energy. No attack possible." << std::endl;
	else
	{
		this->_energyPoints -= 1;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
	}
	std::cout << "\t" << this->_name << ": Hit Points: " << this->_hitPoints << " || Energy Points: " << this->_energyPoints << std::endl;
}

void	ScavTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoints > 0)
	{
		std::cout << this->_name << " has been attacked and lost " << amount
		<< " hit points." << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints <= 0)
		{
			this->_hitPoints = 0;
			std::cout << this->_name << " is dead." << std::endl;
		}
	}
	else
	{
		std::cout << this->_name << " is already dead. No attack was effective." << std::endl;
	}
	std::cout << "\t" << this->_name << ": Hit Points: " << this->_hitPoints << " || Energy Points: " << this->_energyPoints << std::endl;
}
void	ScavTrap::beRepaired( unsigned int amount )
{
	if (this->_hitPoints == 0)
		std::cout << this->_name << "is dead. No repair possible." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << "has no energy. No repair possible." << std::endl;
	else
	{
		this->_energyPoints -= 1;
		std::cout << "ScavTrap " << this->_name << " repaired itself, getting " 
		<< amount << " hit points." << std::endl;
	}
	std::cout << "\t" << this->_name << ": Hit Points: " << this->_hitPoints << " || Energy Points: " << this->_energyPoints << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name << " now in Gate keeper mode." << std::endl;
}