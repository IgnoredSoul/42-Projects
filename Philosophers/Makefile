NAME = philo

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCES = ./philosophers_actions/*.c \
		  ./philosophers_utils/*.c \
		  ./user_arguments_check/*.c \
		  ./main.c

all:
	$(CC) $(FLAGS) $(SOURCES) -o $(NAME)

fclean: 
	@rm -rf $(NAME)

re: fclean all