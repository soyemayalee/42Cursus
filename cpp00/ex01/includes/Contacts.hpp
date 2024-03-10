
#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#ifndef PRINT_DEBUG
# define PRINT_DEBUG	false
#endif

#define RED			"\033[31m"
#define BLUE		"\033[0;34m"
#define NO_COLOUR	"\033[0m"

class PhoneBook;

class Contact {
	public:
		Contact();
		~Contact();
		int		createContact();
		void	displayDetails() const;

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_secret;

};

#endif
