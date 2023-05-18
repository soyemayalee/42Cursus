CNAME		= client

SNAME		= server

CNAME_BONUS	= client_bonus

SNAME_BONUS	= server_bonus

PRINTF		= printf/libftprintf.a

SRCC_FILE	= client.c utils.c

SRCS_FILE	= server.c utils.c

OBJC		= ${SRCC_FILE:.c=.o}

OBJS		= ${SRCS_FILE:.c=.o}

SRCCB_FILE	= client_bonus.c utils_bonus.c

SRCSB_FILE	= server_bonus.c utils_bonus.c

OBJC_BONUS		= ${SRCCB_FILE:.c=.o}

OBJS_BONUS		= ${SRCSB_FILE:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

LFLAGS		= -Lprintf -lftprintf

RM			= rm -rf

all: ${CNAME} ${SNAME}

${PRINTF}: 
	@${MAKE} -C printf

${CNAME}: ${PRINTF} ${OBJC}
	${CC} ${CFLAGS} ${OBJC} $(LFLAGS) -o client

${SNAME}: ${PRINTF} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} $(LFLAGS) -o server

bonus: ${CNAME_BONUS} ${SNAME_BONUS}

${CNAME_BONUS}: ${CNAME} ${SNAME} ${PRINTF} ${OBJC_BONUS}
	${CC} ${CFLAGS} ${OBJC_BONUS} $(LFLAGS) -o client_bonus

${SNAME_BONUS}: ${PRINTF} ${OBJS_BONUS}
	${CC} ${CFLAGS} ${OBJS_BONUS} $(LFLAGS) -o server_bonus

clean:
	${RM} ${OBJC}
	${RM} ${OBJS}
	${RM} ${OBJC_BONUS}
	${RM} ${OBJS_BONUS}
	${RM} printf/*.o

fclean:	clean
	${RM} ${CNAME}
	${RM} ${SNAME}
	${RM} ${CNAME_BONUS}
	${RM} ${SNAME_BONUS}
	${RM} ${PRINTF}
	
re:	fclean all

.PHONY:	all clean fclean re