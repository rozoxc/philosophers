NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = philo.c \
	philo_utils.c \
	
HEADER = philosopher.h
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm  $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

