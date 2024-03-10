#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#ifndef PRINT_DEBUG
# define PRINT_DEBUG	false
#endif

#ifndef CONTACT_MAX
# define CONTACT_MAX 8
#endif

#define WIDTH			10
#define CONTACT_MAX		8
#define ROW_SEP			" | "
#define NUM_ROWS			4
#define NO_COLOUR			"\033[0m"
#define BLUE		"\033[0;34m"

#include "Contacts.hpp"

class Prompt;

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact(Contact newContact);
		int		hasContacts() const ;
		void	showContacts();
		void	showSpecifics(int index) const;

	private:
		Contact	_contactList[CONTACT_MAX];
		size_t	_contactCount;
		size_t	_contactLastIndex;
		void	printBook(std::string str) const;
};

#endif
