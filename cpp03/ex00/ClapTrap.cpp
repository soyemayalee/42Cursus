
#include "ClapTrap.hpp"


/* constructors & destructors */
ClapTrap::ClapTrap( void )
{
	this->_name = "unknown";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;

	std::cout << this->_name << " has been created through default constructor" << std::endl;
}

ClapTrap::ClapTrap( std::string name )
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;

	std::cout << this->_name << " has been created through name-given constructor" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &input)
{
	*this = input;
	std::cout << this->_name << " has been created through copy constructor" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << this->_name << " has been destroyed through destructor" << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& input )
{
	this->_name = input._name;
	this->_hitPoints = input._hitPoints;
	this->_energyPoints = input._energyPoints;
	this->_attackDamage = input._attackDamage;
	return (*this);
}

/* functions */

void	ClapTrap::attack( const std::string& target )
{
	//costs 1 energy point
	if (this->_hitPoints == 0)
		std::cout << this->_name << " is dead. No attack possible." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << "has no energy. No attack possible." << std::endl;
	else
	{
		this->_energyPoints -= 1;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
	}
	std::cout << "\tHit Points: " << this->_hitPoints << " || Energy Points: " << this->_energyPoints << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
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

void	ClapTrap::beRepaired( unsigned int amount )
{
	//costs 1 energy point
	if (this->_hitPoints == 0)
		std::cout << this->_name << " is dead. No repair possible." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << "has no energy. No repair possible." << std::endl;
	else
	{
		this->_energyPoints -= 1;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repaired itself, getting " 
		<< amount << " hit points." << std::endl;
	}
	std::cout << "\tHit Points: " << this->_hitPoints << " || Energy Points: " << this->_energyPoints << std::endl;
}