NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
SIZE       ?= 500
ARG        := $(shell seq 1 $(SIZE) | shuf | tr '\n' ' ')

LIBFT_DIR   = ft_libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = ps_parser.c push_swap.c ps_utils.c ps_utils_2.c ps_benchmark.c ps_error.c \
              ps_medium_alg.c ps_ops.c ps_ops_2.c ps_simple_alg.c #ps_complex.c

BONUS_SRCS  = ps_parser.c ps_checker.c ps_utils.c ps_utils_2.c ps_error.c ps_ops.c ps_ops_2.c \
              get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

adaptive: all bonus
	@./$(NAME) --bench $(ARG) 2> bench.txt | ./$(BONUS_NAME)
	@cat bench.txt

simple: all bonus
	@./$(NAME) --bench --simple $(ARG) 2> bench.txt | ./$(BONUS_NAME)
	@cat bench.txt

medium: all bonus
	@./$(NAME) --bench --medium $(ARG) 2> bench.txt | ./$(BONUS_NAME)
	@cat bench.txt

complex: all bonus
	@./$(NAME) --bench --complex $(ARG) 2> bench.txt | ./$(BONUS_NAME)
	@cat bench.txt

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) bench.txt
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus adaptive simple medium complex