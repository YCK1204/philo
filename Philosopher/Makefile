NAME = philo
CC = cc
FLAG = -Wall -Wextra -Werror #-fsanitize=thread
SRCS = $(wildcard ./Sources/*.c)
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(FLAG) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAG) -o $@ $^

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: re all clean fclean
