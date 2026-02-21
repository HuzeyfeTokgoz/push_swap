NAME    = push_swap.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = push_swap.c push_swap_utils.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
