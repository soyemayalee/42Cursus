NAME		= push_swap

SRCS	= pushswap.c \
		argument.c \
		basic_utils.c \
		few_sort.c \
		index_utils.c \
		lst_utils.c \
		many_sort.c \
		operations_push.c \
		operations_reverse_rotate.c \
		operations_rotate.c \
		operations_swap.c \
		related_utils.c \
		word_number_utils.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address

RM			= rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o push_swap

test2: $(NAME)	
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Number of Commands : "
	@./push_swap $(ARG) | wc -l

test3: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Number of Commands : "
	@./push_swap $(ARG) | wc -l

test4: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 4))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Number of Commands : "
	@./push_swap $(ARG) | wc -l

test5: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 5))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Number of Commands : "
	@./push_swap $(ARG) | wc -l

test100: $(NAME)
	$(eval ARG = $(shell shuf -i 0-100 -n 100))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Number of Commands : "
	@./push_swap $(ARG) | wc -l

test500: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Number of Commands : "
	@./push_swap $(ARG) | wc -l

test1000: $(NAME)	
	$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Number of Commands: "
	@./push_swap $(ARG) | wc -l

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}
	
re:	fclean all

.PHONY:	all clean fclean re test2 test3 test5 test100 test500 test1000