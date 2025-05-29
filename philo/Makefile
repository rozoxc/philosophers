NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror -fsanitize=address
SRC = philo.c \
	philo_utils.c \
	init.c \
	time.c \
	action.c \
	ft_atoi.c \
	algo_philo.c \
	monitor.c \
	mutex_safe.c \
	parse_input.c \
	
HEADER = philosopher.h
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm  -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
.PHONY: all clean fclean re
