NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

LIBFT_DIR   = ft_libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS    = push_swap.c push_swap_utils.c push_swap_utils_2.c \
			push_swap_mode.c push_swap_mode_2.c push_swap_alg.c

OBJS    = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)
	
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
