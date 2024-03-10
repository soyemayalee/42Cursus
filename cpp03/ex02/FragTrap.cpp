

#include "FragTrap.hpp"

/* constructors & destructors */

FragTrap::FragTrap( void ): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " has been created through fragtrap default constructor" << std::endl;

}

FragTrap::FragTrap( std::string name ): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " has been created through fragtrap name-given constructor" << std::endl;
}

FragTrap::FragTrap( const FragTrap &input ): ClapTrap(input)
{
	std::cout << "FragTrap " << this->_name << " has been created through fragtrap copy constructor" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " has been destroyed through fragtrap destructor" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& input )
{
	this->_name = input._name;
	this->_hitPoints = input._hitPoints;
	this->_energyPoints = input._energyPoints;
	this->_attackDamage = input._attackDamage;
	return (*this);
}

/* functions */

void	FragTrap::attack( const std::string& target )
{
	if (this->_hitPoints == 0)
		std::cout << this->_name << "is dead. No attack possible." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << "has no energy. No attack possible." << std::endl;
	else
	{
		this->_energyPoints -= 1;
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
	}
	std::cout << "\t" << this->_name << ": Hit Points: " << this->_hitPoints << " || Energy Points: " << this->_energyPoints << std::endl;
}

void	FragTrap::takeDamage( unsigned int amount )
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

void	FragTrap::beRepaired( unsigned int amount )
{
	if (this->_hitPoints == 0)
		std::cout << this->_name << "is dead. No repair possible." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << this->_name << "has no energy. No repair possible." << std::endl;
	else
	{
		this->_energyPoints -= 1;
		std::cout << "FragTrap " << this->_name << " repaired itself, getting " 
		<< amount << " hit points." << std::endl;
	}
	std::cout << "\t" << this->_name << ": Hit Points: " << this->_hitPoints << " || Energy Points: " << this->_energyPoints << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << "FragTrap " << this->_name << " wants to give you a high-five!" << std::endl;
	}
}