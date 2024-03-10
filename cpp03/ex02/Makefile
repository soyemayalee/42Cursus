NAME		= FragTrap

SRCS		= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJS		= ${SRCS:.cpp=.o}

CXX			= c++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

RM			= rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CFLAGS} ${OBJS}  -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}
	
re:	fclean all

.PHONY:	all clean fclean re