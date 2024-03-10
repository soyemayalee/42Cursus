NAME = Animal

FLAGS = -Wall -Wextra -Werror -std=c++98 #-g

CC = c++

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

clean :
	rm -f *.o */*.o 

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all re