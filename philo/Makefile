SRCS = philo.c ft_calloc.c ft_atoi.c death_action.c free_ressources.c init.c get_time.c philo_action.c run.c \
	get_data.c philo_msg.c forks.c get_info.c join.c philo_routine.c 

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

NAME = philo
OBJDIR = obj

CC = cc
RM = rm -rf
CFLAGS =  -Wall -Wextra -Werror -fsanitize=thread -g
THREAD = -pthread

$(OBJDIR)/%.o: %.c philo.h
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(THREAD) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(THREAD) -o $(NAME) $(OBJS)

clean: 
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re