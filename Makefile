NAME			= so_long

NAME_BONUS		= so_long_bonus

SRCS			= ./srcs/so_long.c \
				./srcs/launch_game.c \
				./srcs/validate_map.c \
				./srcs/validate_file.c \
				./srcs/free_error.c \
				./srcs/key_hook.c \
				./srcs/set_graphics.c \
				./srcs/flood_fill.c

SRCSB			= ./srcsb/so_long_bonus.c \
				./srcsb/launch_game_bonus.c \
				./srcsb/validate_map_bonus.c \
				./srcsb/validate_file_bonus.c \
				./srcsb/free_error_bonus.c \
				./srcsb/key_hook_bonus.c \
				./srcsb/set_graphics_bonus.c \
				./srcsb/flood_fill_bonus.c

OBJS			= ${SRCS:.c=.o}

OBJSB			= ${SRCSB:.c=.o}

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror -g #-fsanitize=address

INCLUDES_PATH	= ./includes/

LIBFT_PATH		= ./includes/libft/

MINILIBX_LINUX	= ./includes/minilibx-linux

INCS			= -I$(INCLUDES_PATH) -I$(LIBFT_PATH) -I$(MINILIBX_LINUX)

INCLIB_LINUX	= -L./usr/lib/x86_64-linux-gnu/ -L$(LIBFT_PATH) -lft -L$(MINILIBX_LINUX) -lmlx -lX11 -lXext

RM			= rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ${LIBFT_PATH}
	${MAKE} -C ${MINILIBX_LINUX}
	${CC} ${CFLAGS} ${OBJS} ${INCS} ${INCLIB_LINUX} -o so_long

${NAME_BONUS}: ${NAME} ${OBJSB}
	${MAKE} -C ${LIBFT_PATH}
	${MAKE} -C ${MINILIBX_LINUX}
	${CC} ${CFLAGS} ${OBJSB} ${INCS} ${INCLIB_LINUX} -o so_long_bonus

bonus: ${NAME_BONUS}

clean:
	${MAKE} -C ${LIBFT_PATH} clean
	${MAKE} -C ${MINILIBX_LINUX} clean
	${RM} ${OBJS}
	${RM} ${OBJSB}

fclean:	clean
	${MAKE} -C ${LIBFT_PATH} fclean
	${RM} ${NAME}
	${RM} ${NAME_BONUS}

	
re:	fclean all

.PHONY:	all clean fclean re test2 test3 test5 test100 test500 test1000
