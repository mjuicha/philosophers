SRC = philo.c ft_atoi.c get_info.c

OBJ = $(SRC:.c=.o)

NAME = philo

%.o : %.c philosophers.h
	 cc -Wall -Wextra -Werror -pthread -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) 
	cc $(OBJ) -pthread -o $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re