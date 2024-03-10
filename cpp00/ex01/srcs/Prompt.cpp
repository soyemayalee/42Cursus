#include <iostream>
#include <string>
#include <cctype>
#include "../includes/Prompt.hpp"

Prompt::Prompt()
{
	if (PRINT_DEBUG)
		std::cout << "Prompt constructor called" << std::endl;
}

Prompt::~Prompt()
{
	if (PRINT_DEBUG)
		std::cout << "Prompt destructor called" << std::endl;
}

bool Prompt::goodRange(const std::string& str, int max)
{
	for (char c : str)
	{
		if (!std::isdigit(c))
			return (false);
	}
	int number = std::stoi(str);
	if (number > max - 1 || number < 0)
		return (false);
	return (true);
}

void Prompt::runPrompt(void)
{
	int run = 1;
	while (run == 1)
	{
		std::string command;
		std::cout << "Please Check the Available Commands:\n";
		std::cout << "-ADD\n-SEARCH\n-EXIT\n";
		std::cout << "\nPlease Enter Your Command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			Contact newContact;
			if (newContact.createContact() == 0)
			{
				phoneBook.addContact(newContact);
			}
		}
		else if (command == "SEARCH")
		{
			if (phoneBook.hasContacts() == 0)
			{
				std::cout << std::endl;
				std::cout << RED << "--------------------------" << NO_COLOUR << std::endl;
				std::cout << RED << "   NO EXISTING CONTACTS   " << NO_COLOUR << std::endl;
				std::cout << RED << "--------------------------" << NO_COLOUR << std::endl;
				std::cout << std::endl;
			}
			else
			{
				phoneBook.showContacts();
				std::cout << std::endl;
				std::string index;
				int count = 0;
				while (count < 3)
				{
					std::cout << "Type Index to See Specifics: ";
					std::getline(std::cin, index);
					if (goodRange(index, phoneBook.hasContacts()) == false)
					{
						if (count != 2)
						{
							std::cout << RED << "Wrong Index Input. Please Check Again" << std::endl;
							std::cout << "-----Total " << count + 1 <<" / 3 Attempts Made-----" << NO_COLOUR << std::endl;
							std::cout << std::endl;
						}
						count++;
					}
					else
						count = 4;
				}
				if (count == 3)
				{
					std::cout << RED << "!!! Invalid Input: 3 / 3 Times !!!" << NO_COLOUR << std::endl ;
					std::cout << "----Going Back to Home----" << std::endl;
					std::cout << std::endl;
				}
				else
				{
					phoneBook.showSpecifics(std::stoi(index));
				}
			}
		}
		else if (command == "EXIT")
			run = 0 ;
		else
			std::cout << RED << "Cannot Find Command\n\n" << NO_COLOUR << std::endl;
	}
}
