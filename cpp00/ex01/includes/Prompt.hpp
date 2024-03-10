#ifndef PROMPT_HPP
# define PROMPT_HPP

#ifndef PRINT_DEBUG
# define PRINT_DEBUG	false
#endif

#include "PhoneBook.hpp"

class Prompt
{
	public:
		Prompt();
		~Prompt();
		void	runPrompt();
		bool goodRange(const std::string& str, int max);
	private:
		PhoneBook	phoneBook;
};

#endif