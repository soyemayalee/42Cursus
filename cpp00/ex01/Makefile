NAME		= phonebook

SRCS		= srcs/main.cpp srcs/PhoneBook.cpp srcs/Contacts.cpp srcs/Prompt.cpp

OBJS		= ${SRCS:.cpp=.o}

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -g -std=c++98

RM			= rm -rf

INCLUDES 	= -I includes 

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDES} ${OBJS}  -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}
	
re:	fclean all

.PHONY:	all clean fclean re