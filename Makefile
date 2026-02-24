NAME    = push_swap.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = push_swap.c push_swap_utils.c push_swap_utils_2.c \
			push_swap_mode.c push_swap_mode_2.c push_swap_alg.c

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
