SRCS	= ft_printf.c ft_itoa.c hex.c pointer.c str_num_percent.c unsigned.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

${NAME}: ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus
