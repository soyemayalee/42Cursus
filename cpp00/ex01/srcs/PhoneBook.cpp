#include <iostream>
#include <string>
#include <iomanip> //for setw
#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(): _contactCount(0), _contactLastIndex(0)
{
	if (PRINT_DEBUG)
		std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	if (PRINT_DEBUG)
		std::cout << "PhoneBook destructor called" << std::endl;
}

void	PhoneBook::addContact(Contact newContact)
{
	if (this->_contactCount < CONTACT_MAX)
		this->_contactCount++;
	if (this->_contactLastIndex == CONTACT_MAX)
		_contactLastIndex = 0;
	this->_contactList[_contactLastIndex] = newContact;
	_contactLastIndex++;
}

void	PhoneBook::printBook(std::string str) const
{
	static size_t	index = 1;

	if (str.length() > WIDTH)
		std::cout << str.substr(0, WIDTH - 1) << ".";
	else
		std::cout << std::setw(WIDTH) << str;
	if (index + 1 != NUM_ROWS)
	{
		index++;
		std::cout << ROW_SEP;
	}
	else
	{
		index = 1;
		std::cout << std::endl;
	}
}

void	PhoneBook::showContacts()
{
	std::cout << std::right
		<< BLUE << std::setw(WIDTH) << "Index" << NO_COLOUR<< ROW_SEP
		<< BLUE << std::setw(WIDTH) << "First Name" << NO_COLOUR << ROW_SEP
		<< BLUE << std::setw(WIDTH) << "Last Name" << NO_COLOUR << ROW_SEP
		<< BLUE << std::setw(WIDTH) << "Nickname" << NO_COLOUR << std::endl;
	int	i = 0;
	while (i < _contactCount)
	{
		std::cout << std::right << std::setw(WIDTH) << i << ROW_SEP;
		printBook(_contactList[i].getFirstName());
		printBook(_contactList[i].getLastName());
		printBook(_contactList[i].getNickName());
		i++;
	}
}

void	PhoneBook::showSpecifics(int index) const
{
	_contactList[index].displayDetails();
}

int	PhoneBook::hasContacts() const //const means it's a read-only function
{
	return (_contactCount);
}