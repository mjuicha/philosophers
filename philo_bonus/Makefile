SRCS = philo_bonus.c ft_atoi.c get_data.c get_info.c get_time.c kill_process.c \
		life_cycle.c msg.c routine.c run.c semaphores.c free_ressources.c

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

NAME = philo_bonus
OBJDIR = obj

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
THREAD = -pthread

$(OBJDIR)/%.o: %.c philo_bonus.h
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
