#include <iostream>
#include <string>
#include "../includes/Contacts.hpp"

Contact::Contact()
{
	if (PRINT_DEBUG)
		std::cout << "Contact default constructor called" << std::endl;
}

Contact::~Contact()
{
	if (PRINT_DEBUG)
		std::cout << "Contact destructor called" << std::endl;
}

int Contact::createContact(void)
{   
	std::string first;
	std::string last;
	std::string nick;
	std::string number;
	std::string darkSecret;

	std::cout << "First Name: ";
	std::getline(std::cin, first);
	std::cout << "Last Name: ";
	std::getline(std::cin, last);
	std::cout << "Nickname: ";
	std::getline(std::cin, nick);
	std::cout << "Phone Number: ";
	std::getline(std::cin, number);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, darkSecret);
	if (!first.empty() && !last.empty() && !nick.empty() && !number.empty() && !darkSecret.empty())
	{
		this->_firstName = first;
		this->_lastName = last;
		this->_nickname = nick;
		this->_phoneNumber = number;
		this->_secret = darkSecret;

		std::cout << std::endl;
		std::cout << BLUE << "--------------------------" << NO_COLOUR << std::endl;
		std::cout << BLUE << "Contact Successfully Added" << NO_COLOUR << std::endl;
		std::cout << BLUE << "--------------------------" << NO_COLOUR << std::endl;
		std::cout << std::endl;
		return (0);
	}
	std::cout << std::endl;
	std::cout << RED << "------------------------------------------" << NO_COLOUR << std::endl;
	std::cout << RED << "      You cannot have empty info\n" << NO_COLOUR << std::endl;
	std::cout << RED << "The information was not saved to contacts." << NO_COLOUR << std::endl;
	std::cout << RED << "             Please try again." << NO_COLOUR << std::endl;
	std::cout << RED << "------------------------------------------" << NO_COLOUR << std::endl;
	std::cout << std::endl;
	return (1);

}

void	Contact::displayDetails() const
{
	std::cout << std::endl;
	std::cout << BLUE << "-----------------------------------" << NO_COLOUR << std::endl;
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _secret << std::endl;
	std::cout << BLUE << "-----------------------------------" << NO_COLOUR << std::endl;
	std::cout << std::endl;
}

std::string	Contact::getFirstName() const
{
	return (this->_firstName);
}

std::string	Contact::getLastName() const
{
	return (this->_lastName);
}

std::string	Contact::getNickName() const
{
	return (this->_nickname);
}