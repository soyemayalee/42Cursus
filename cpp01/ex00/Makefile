NAME		= zombie

SRCS		= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJS		= ${SRCS:.cpp=.o}

CC			= g++

CFLAGS		= -Wall -Wextra -Werror -g -std=c++98

RM			= rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS}  -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}
	
re:	fclean all

.PHONY:	all clean fclean re