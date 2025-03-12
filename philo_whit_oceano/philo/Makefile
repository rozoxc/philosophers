NAME = philo
CC = cc  
FLAGS = -Wall -Werror -Wextra
HEADER = philo.h 

SRC = philo.c \
	philo_utils.c \
	ft_atoi.c \
	parse.c \
	init.c \
	time.c \
	safe_mutex.c \
	getters_setters.c \
	simulation.c \

OBJS = $(SRC:.c=.o)

all : $(NAME)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o:$.c $(HEADER)
	$(CC) $(FLAGS) -c $> -o $@

clean:
	rm $(OBJS)
fclean : clean
	rm -rf $(NAME)

.PHONY: clean